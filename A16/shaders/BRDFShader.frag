#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir0;
	vec3 lightColor0;
	vec3 lightDir1;
	vec3 lightColor1;
	vec3 lightDir2;
	vec3 lightColor2;
	vec3 lightDir3;
	vec3 lightColor3;
	vec3 eyePos;
	vec4 selector;
} gubo;

/**** Modify from here *****/


// L : the direction of the light
// N : the direction of the normal vector
// V : the direction of the view vector
// C : the main color required by the model

//BRDF = diffuse (main color of the object)+ specular(reflection of shiny objects)


//each point of an object hit by a ray of light, reflects it with uniform probability in all the directions.

vec3 Lambert_Diffuse_BRDF(vec3 L, vec3 N, vec3 V, vec3 C) {
	// Lambert Diffuse BRDF model
	// in all BRDF parameters are:
	// vec3 L : light direction
	// vec3 N : normal vector
	// vec3 V : view direction
	// vec3 C : main color (diffuse color, or specular color)

	float dot_prod = dot(L, N);
	return max(dot_prod, 0) * C;
}


// Some materials are characterized by a phenomenon called retroreflection: they tend to reflect back in the direction of the light
//source. They are characterized by very rough surfaces,

vec3 Oren_Nayar_Diffuse_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, float sigma) {
	// Directional light direction
	// additional parameter:
	// float sigma : roughness of the material


	float A = 1 - 0.5 * ( pow(sigma, 2.0) / (pow(sigma, 2.0) + 0.33));
	float B = 0.45 * ( pow(sigma, 2.0) / (pow(sigma, 2.0) + 0.09));

	vec3 Vi = normalize(L - (dot(L, N) * N));
	vec3 Vr = normalize(V - (dot(V, N) * N));
	float G = max(0, dot(Vi, Vr));
	vec3 Lmat = C * clamp(dot(L, N), 0.0, 1.0);

	float teta_i = acos(dot(L, N));
	float teta_r = acos(dot(V, N));
	float alpha = max(teta_i, teta_r);
	float beta = min(teta_i, teta_r);

	float funct_f = B * sin(alpha) * tan(beta);

	return Lmat * (A + G * funct_f);
}


//In the Phong model, the specular reflection has the same angle as the incoming ray with respect to the normal vector,
//but it is oriented in the opposite direction

vec3 Phong_Specular_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, float gamma)  {
	// Phong Specular BRDF model
	// additional parameter:
	// float gamma : exponent of the cosine term
	vec3 rlx = -reflect(L, N);
	float clamp_val = clamp(pow(dot(V, rlx),gamma), 0.0, 1.0);

	return clamp_val * C;
}


//Toon shading simplifies the output color range, using only discrete values according to a set of thresholds.

vec3 Toon_Diffuse_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, vec3 Cd, float thr) {
	// Toon Diffuse Brdf
	// additional parameters:
	// vec3 Cd : color to be used in dark areas
	// float thr : color threshold
	if(dot(L, N) >= thr)
		return C;
	else
		return Cd;
}

vec3 Toon_Specular_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, float thr)  {
	// Directional light direction
	// additional parameter:
	// float thr : color threshold
	vec3 rlx = -reflect(L, N);
	if(dot(V, rlx) >= thr)
		return C;
	else
		return vec3(0,0,0);
}


/**** To here *****/



//DIFFFUSE
vec3 BRDF_D(vec3 L, vec3 N, vec3 V, vec3 C) {
	return gubo.selector.x * Lambert_Diffuse_BRDF(L, N, V, C) +
		   (1.0 - gubo.selector.x) * (1.0 - gubo.selector.y) * 
		   			Toon_Diffuse_BRDF(L, N, V, C, 0.2f * C, 0.5) +
		   (1.0 - gubo.selector.x) * (gubo.selector.y) * 
		   			Oren_Nayar_Diffuse_BRDF(L, N, V, C, 1.5);
}

//SPECULAR
vec3 BRDF_S(vec3 L, vec3 N, vec3 V, vec3 C) {
	return Phong_Specular_BRDF(L, N, V, C, 200.0f) * gubo.selector.z +
		   (1.0 - gubo.selector.x) * (1.0 - gubo.selector.y) * 
		   			Toon_Specular_BRDF(L, N, V, vec3(1,1,1), 0.97f);
}

void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
	
	float AmbFact = 0.025;
	
	vec3 DiffColor = texture(texSampler, fragTexCoord).rgb * gubo.selector.w + vec3(1,1,1) * (1-gubo.selector.w);
	vec3 Diffuse = vec3(0,0,0);
	
	Diffuse += BRDF_D(gubo.lightDir0, Norm, EyeDir, DiffColor) * gubo.lightColor0;
	Diffuse += BRDF_D(gubo.lightDir1, Norm, EyeDir, DiffColor) * gubo.lightColor1;
	Diffuse += BRDF_D(gubo.lightDir2, Norm, EyeDir, DiffColor) * gubo.lightColor2;
	Diffuse += BRDF_D(gubo.lightDir3, Norm, EyeDir, DiffColor) * gubo.lightColor3;
	
	vec3 Specular = vec3(0,0,0);
	Specular += BRDF_S(gubo.lightDir0, Norm, EyeDir, vec3(1,1,1)) * gubo.lightColor0;
	Specular += BRDF_S(gubo.lightDir1, Norm, EyeDir, vec3(1,1,1)) * gubo.lightColor1;
	Specular += BRDF_S(gubo.lightDir2, Norm, EyeDir, vec3(1,1,1)) * gubo.lightColor2;
	Specular += BRDF_S(gubo.lightDir3, Norm, EyeDir, vec3(1,1,1)) * gubo.lightColor3;

	vec3 Ambient = AmbFact * DiffColor;
	
	outColor = vec4(Diffuse + Specular + Ambient, 1.0f);	
}