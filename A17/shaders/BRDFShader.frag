#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	// Direct lights parameters (for diffuse and specular)
	vec3 lightDir0;
	vec3 lightColor0;
	vec3 lightDir1;
	vec3 lightColor1;
	vec3 lightDir2;
	vec3 lightColor2;
	vec3 lightDir3;
	vec3 lightColor3;

	// Ambient light parameters
	vec3 AmbColor;	// also Bottom color for Hemispheric light,
					//      Constant term for Spherical Harmonics light
	vec3 TopColor;	// also DyColor for Spherical Harmonics light
	vec3 DzColor;
	vec3 DxColor;
	
	// Other parameters (not relevant for the exercise)
	vec3 eyePos;
	vec4 selector;
} gubo;

/**** Modify from here *****/

layout(location = 2) in vec2 fragTexCoord;
layout(location = 1) in vec3 fragNorm;
layout(location = 0) in vec3 fragPos;

layout(location = 0) out vec4 outColor;

vec3 Case1_Color(vec3 N, vec3 V, vec3 Cd, vec3 Ca, float sigma) {
	// Oren Nayar Diffuse + Ambient
	// No Specular
	// One directional light (lightDir0 and lightColor0)
	//
	// Parameters are:
	//
	// vec3 N : normal vector
	// vec3 V : view direction
	// vec3 Cd : main color (diffuse color)
	// vec3 Ca : ambient color
	// float sigma : roughness of the material
	
	//Oren NAYAR diffuse
	float A = 1 - 0.5 * ( pow(sigma, 2.0) / (pow(sigma, 2.0) + 0.33));
	float B = 0.45 * ( pow(sigma, 2.0) / (pow(sigma, 2.0) + 0.09));

	vec3 Vi = normalize(gubo.lightDir0 - (dot(gubo.lightDir0, N) * N));
	vec3 Vr = normalize(V - (dot(V, N) * N));
	float G = max(0, dot(Vi, Vr));
	vec3 Lmat = Cd * clamp(dot(gubo.lightDir0, N), 0.0, 1.0);

	float teta_i = acos(dot(gubo.lightDir0, N));
	float teta_r = acos(dot(V, N));
	float alpha = max(teta_i, teta_r);
	float beta = min(teta_i, teta_r);

	float funct_f = B * sin(alpha) * tan(beta);

	vec3 fr = Lmat * (A + G * funct_f);

	//end of oren nayar

	//l * fr + la*fa --> la = color value, fa = amb
	vec3 res = gubo.lightColor0 * fr + Ca * gubo.AmbColor;
	return res;
}

vec3 Case2_Color(vec3 N, vec3 V, vec3 Cd, vec3 Ca) {
	// Lambert Diffuse + Hemispheric
	// No Specular
	// One directional light (lightDir0 and lightColor0)
	// Hemispheric light oriented along the y-axis
	//
	// Parameters are:
	//
	// vec3 N : normal vector
	// vec3 V : view direction
	// vec3 Cd : main color (diffuse color)
	// vec3 Ca : ambient color
	
	//LAMBERT DIFFUSE
	float dot_prod = dot(gubo.lightDir0, N);
	vec3 fr = max(dot_prod, 0) * Cd;
	//end of lambert diffuse

	//l * fr + la*fa   -> fa is also considered as ma and is the main color of the object, ambient light reflection 
	vec3 res = gubo.lightColor0 * fr + Ca * ((((dot(gubo.lightDir0, N) + 1) / 2) * gubo.TopColor) + (((1 - (dot(gubo.lightDir0, N))) / 2) * gubo.AmbColor ));
	return res;
}

vec3 Case3_Color(vec3 N, vec3 V, vec3 Cs, vec3 Ca, float gamma)  {
	// Spherical Harmonics
	// Blinn Specular
	// Four directional lights (lightDir0 to lightDir3, and lightColor0 to lightColor3)
	//
	// Parameters are:
	//
	// vec3 N : normal vector
	// vec3 V : view direction
	// vec3 Cs : specular color
	// vec3 Ca : ambient color
	// float gamma : Blinn exponent
	
	float pow_0 = pow(dot(N, normalize(gubo.lightDir0 + V)), gamma);
	float pow_1 = pow(dot(N, normalize(gubo.lightDir1 + V)), gamma);
	float pow_2 = pow(dot(N, normalize(gubo.lightDir2 + V)), gamma);
	float pow_3 = pow(dot(N, normalize(gubo.lightDir3 + V)), gamma);


	vec3 fr_0 = Cs * clamp(pow_0, 0.0, 1.0); 
	vec3 fr_1 = Cs * clamp(pow_1, 0.0, 1.0);
	vec3 fr_2 = Cs * clamp(pow_2, 0.0, 1.0);
	vec3 fr_3 = Cs * clamp(pow_3, 0.0, 1.0);

	vec3 Ia = gubo.AmbColor + N.x * gubo.DxColor + N.y * gubo.TopColor + N.z * gubo.DzColor;

	vec3 res = gubo.lightColor0 * fr_0 + gubo.lightColor1 * fr_1 + gubo.lightColor2 * fr_2 + gubo.lightColor3 * fr_3;

	return res + Ia * Ca;
}



/**** To here *****/




void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
	
	float AmbFact = 0.025;
	
	vec3 DifCol = texture(texSampler, fragTexCoord).rgb * gubo.selector.w +
				  vec3(1,1,1) * (1-gubo.selector.w);



	vec3 CompColor = gubo.selector.x *
						Case1_Color(Norm, EyeDir, DifCol, DifCol, 1.2f) +
					 gubo.selector.y *
						Case2_Color(Norm, EyeDir, DifCol, DifCol) +
					 gubo.selector.z *
						Case3_Color(Norm, EyeDir, vec3(1.0f,1.0f,1.0f), DifCol, 200.0f);
	
	outColor = vec4(CompColor, 1.0f);	
}