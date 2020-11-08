#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;
layout (location = 3) in vec3 colour;

out vec3 Normal;
out vec2 Texcoords;
out vec3 Colour;
out vec3 FragPosition;


uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{

    Normal = mat3(inverse(transpose(model))) * normal;

	Texcoords = texCoords;
	FragPosition = vec3(model * vec4(position, 1.0f));
	gl_Position = proj * view * model * vec4(position, 1.0f); 
	gl_PointSize = gl_Position.z;
	
	//Particles NEEDS TO BE FIXED
	vec4 cameraDistance = view * model * vec4(position,1.0f);
	float Lenght = cameraDistance.x + cameraDistance.y + cameraDistance.z;
	float Attenuation = ((sqrt(inverse(0.1))) * Lenght);
	gl_PointSize = Attenuation * 100;
	gl_Position = proj * view * model * vec4(position, 1.0f); 



}