#version 450
#extension GL_ARB_separate_shader_objects : enable

	mat4 mvpMat;
	mat4 mMat;
	mat4 nMat;
} ubo;

layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexCoord;

layout(location = 0) out vec3 fragTexCoord;

{
    fragTexCoord = inPosition;
    vec4 pos = ubo.mvpMat * vec4(inPosition, 1.0);
    gl_Position = pos.xyww;
}  