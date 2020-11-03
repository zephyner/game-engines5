#include "SpriteSurface.h"


SpriteSurface::SpriteSurface(std::string imageName_, glm::vec2 scale_, float angle_, glm::vec4 colour_) : scale(1.0f), angle(0)
{
	//set up vertex list
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	//save parameter values for member variables
	//scale set to 1.0f and angle set to 0 ->

	//create texture based on image name given


	//save textureID


	// get witdh and height of surface from texturehandler


	//call to generatebuffers to set up VAO, VBO, and get location of all uniform variables
	GenerateBuffers();
}

SpriteSurface::~SpriteSurface()
{

}

void SpriteSurface::Draw(Camera* camera_, std::vector<glm::mat4> instances_)
{

}

float SpriteSurface::GetWidth()
{

}

float SpriteSurface::GetHeight()
{

}

void SpriteSurface::GenerateBuffers()
{

}