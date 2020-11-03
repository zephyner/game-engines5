#include "SpriteSurface.h"


SpriteSurface::SpriteSurface(std::string imageName_, glm::vec2 scale_, float angle_, glm::vec4 tintColour_) : scale(1), angle(0)
{
	//set up vertex list
	vertexList[0].position = glm::vec2(-0.5, 0.5);
	vertexList[0].texCoords = glm::vec2(0.0, 0.0f);

	vertexList[1].position = glm::vec2(0.5, 0.5);
	vertexList[1].texCoords = glm::vec2(1.0, 0.0);

	vertexList[2].position = glm::vec2(-0.5, -0.5);
	vertexList[2].texCoords = glm::vec2(0.0, 1.0);

	vertexList[3].position = glm::vec2(0.5, -0.5);
	vertexList[3].texCoords = glm::vec2(1.0, 1.0);

	//save parameter values for member variables
	imageName = imageName_;
	scale = scale_;
	angle = angle_;

	//create texture based on image name given
	//save textureID
	// get witdh and height of surface from texturehandler
	if (TextureHandler::GetInstance()->GetTexture(imageName) == 0)
	{
		TextureHandler::GetInstance()->CreateTexture(imageName, "./Resources/GUI" + imageName + ".png");
		width = TextureHandler::GetInstance()->GetTextureData(imageName)->width;
		height = TextureHandler::GetInstance()->GetTextureData(imageName)->height;
		textureID = TextureHandler::GetInstance()->GetTexture(imageName);
	}
	else
	{
		std::cout << "Sprite Surface couldn't create a new texture";
		return;
	}

	//call to generatebuffers to set up VAO, VBO, and get location of all uniform variables
	GenerateBuffers();
}

SpriteSurface::~SpriteSurface()
{
	//just like in mesh class must destroy
	glDeleteVertexArrays(1, &VAO);
	glDeleteVertexArrays(1, &VBO);
}

void SpriteSurface::Draw(Camera* camera_, std::vector<glm::vec2> position_)
{
	// set up texture information
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);

	//setting model and projection uniforms
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera_->getOrthographic()));
	//setting tint uniform
	glUniformMatrix4fv(tintColour, 1, GL_FALSE, NULL);

	//creating our own model matrix
	glUniform3f(projLoc, camera_->GetPosition().x, camera_->GetPosition().y, camera_->GetPosition().z);

	
	//binding the VAO just like in mesh
	glBindVertexArray(VAO);
	for (int i = 0; i < position_.size(); i++)
	{
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(position_[i]));
		glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexList.size());
	}

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

float SpriteSurface::GetWidth()
{
	return width;
}

float SpriteSurface::GetHeight()
{
	return height;
}

void SpriteSurface::GenerateBuffers()
{
	//only using position and texcoords because thats all we have within the struc
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexList.size() * sizeof(Vertex), &vertexList[0], GL_STATIC_DRAW);

	//postion
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	//TEX COORDS
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}