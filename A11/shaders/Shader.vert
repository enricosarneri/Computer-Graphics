#version 450

layout(set = 0, binding = 0) uniform UniformBufferObject { //uniform struct used to communicate among shaders and application
	mat4 worldMat;
	mat4 viewMat;
	mat4 prjMat;
} ubo;

layout(location = 0) in vec3 inPosition; //these are the local coordinates of each vertex

void main() {
	gl_Position = ubo.prjMat * ubo.viewMat * ubo.worldMat * vec4(inPosition, 1.0); //it returns the clipping coordinates obtain by multiplying by M(wvp) matrix
	//it comunicates with the fixed part of the pipeline
}