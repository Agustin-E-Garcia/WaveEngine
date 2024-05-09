#version 450

layout(location = 0) in vec3 inPosition;
layout(location = 1) in mat4 modelMatrix;

layout( push_constant ) uniform constants
{
	mat4 viewMatrix;
	mat4 projectionMatrix;
} PushConstants;

layout(location = 0) out vec3 fragColor;

void main() 
{
    gl_Position = PushConstants.projectionMatrix * PushConstants.viewMatrix * modelMatrix * vec4(inPosition, 1.0);
    fragColor = vec3(1.0f, 1.0f, 1.0f);
}