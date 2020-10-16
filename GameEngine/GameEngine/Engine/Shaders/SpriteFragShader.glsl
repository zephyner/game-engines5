#version 450 core

in vec2 TexCoords;

out vec4 colour;

uniform vec4 tintColour;
uniform sampler2D inputTexture;

void main(){

	vec4 tmpColour =  texture(inputTexture, TexCoords) * tintColour;
	colour = tmpColour;
}