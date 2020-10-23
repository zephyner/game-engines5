#include "SpriteSurface.h"


SpriteSurface::SpriteSurface(std::string imagename_, glm::vec2 scale_, glm::vec2 angle_, glm::vec2 colour_) : scale(1.0f), angle(0)
{
	//set up vertex list
	//glDrawArrays(GL_TRIANGLES, 4, );
	//save parameter values

	//create texture
	//TextureHandler::GetTexture;
	//TextureHandler::CreateTexture;
	//save textureID

	//get width and height

	GenerateBuffers();
}

SpriteSurface::~SpriteSurface()
{
	OnDestroy();
}

void SpriteSurface::Draw(Camera* camera_, std::vector<glm::mat4> instances_)
{
	//glUniform1i(, 0);
	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, );

	//glUniformMatrix4fv(, 1, GL_FALSE, glm::value_ptr(camera_->GetView()));
	//glUniformMatrix4fv(, 1, GL_FALSE, glm::value_ptr(camera_->GetPrespective()));
}

void SpriteSurface::OnDestroy()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

float SpriteSurface::GetWidth()
{
	
}

float SpriteSurface::GetHeight()
{
	
}

void SpriteSurface::SetWidth(float width_)
{

}

void SpriteSurface::SetHeight(float height_)
{

}

void SpriteSurface::GenerateBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, .vertexList.size() * sizeof(Vertex), &subMesh.vertexList[0], GL_STATIC_DRAW);

	//POSITION
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	//NORMAL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	//TEX COORDS
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));
	//COLOUR
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, colour));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}