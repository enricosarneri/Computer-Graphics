#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
	vec3 lightPos;
	vec3 lightColor;
	vec3 eyePos;
	vec4 coneInOutDecayExp;
	vec4 selector;
} gubo;




/**** Modify from here *****/

vec3 direct_light_dir(vec3 pos) {
	// Directional light direction
	vec3 light_dir;
	light_dir = gubo.lightDir;
	return light_dir;
}

vec3 direct_light_color(vec3 pos) {
	// Directional light color
	vec3 light_col;
	light_col = gubo.lightColor;
	return light_col;
}

vec3 point_light_dir(vec3 pos) {
	// Point light direction
	return normalize(gubo.lightPos - pos);
}

vec3 point_light_color(vec3 pos) {
	// Point light color
	return ( pow((gubo.coneInOutDecayExp.z / length(gubo.lightPos - pos)), gubo.coneInOutDecayExp.w) * gubo.lightColor);
}

vec3 spot_light_dir(vec3 pos) {
	// Spot light direction
	return normalize(gubo.lightPos - pos);
}

vec3 spot_light_color(vec3 pos) {
	// Spot light color
	vec3 temp1 = ( pow((gubo.coneInOutDecayExp.z / length(gubo.lightPos - pos)), gubo.coneInOutDecayExp.w) * gubo.lightColor);

	vec3 norm1 = normalize(gubo.lightPos - pos);
	float dot_prod = dot(norm1, gubo.lightDir);
	float temp2 = clamp(((dot_prod - gubo.coneInOutDecayExp.x)/(gubo.coneInOutDecayExp.y - gubo.coneInOutDecayExp.x)) , 0.0, 1.0);
	return temp1 * temp2; 
}

/**** To from here *****/





void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
	
	vec3 lD;	// light direction from the light model
	vec3 lC;	// light color and intensity from the light model
	
	lD = direct_light_dir(fragPos) * gubo.selector.x +
	     point_light_dir(fragPos)  * gubo.selector.y +
	     spot_light_dir(fragPos)   * gubo.selector.z;
	lC = direct_light_color(fragPos) * gubo.selector.x +
	     point_light_color(fragPos)  * gubo.selector.y +
	     spot_light_color(fragPos)   * gubo.selector.z;

	vec3 Diffuse = (texture(texSampler, fragTexCoord).rgb * gubo.selector.w + vec3(1,1,1) * (1-gubo.selector.w)) * (max(dot(Norm, lD),0.0f) );
	vec3 Specular = vec3(pow(max(dot(EyeDir, -reflect(lD, Norm)),0.0f), 64.0f));
	
	outColor = vec4((Diffuse + Specular) * lC, 1.0f);	
}