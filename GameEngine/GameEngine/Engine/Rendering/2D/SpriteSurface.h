#ifndef SPRITESURFACE
#define SPRITESURFACE

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Camera/Camera.h"
#include "../../Graphics/TextureHandler.h"
#include <glm/gtc/matrix_transform.hpp>


//struct is public by default
struct Vertex
{
	glm::vec2 position;
	glm::vec2 texCoords;
};

class SpriteSurface
{
public:
	SpriteSurface(std::string imageName_, glm::vec2 scale_, float angle_, glm::vec4 tintColour_);
	~SpriteSurface();

	void Draw(Camera* camera_, glm::vec2 position_);

	float GetWidth();
	float GetHeight();

private:
	void GenerateBuffers();
	GLuint shaderprogram;
	GLuint VAO, VBO;
	GLuint textureID;
	GLuint modelLoc, projLoc, tintColour, textureLoc;
	std::string imageName;
	glm::vec2 scale;
	float angle, width, height;
	std::vector<Vertex> vertexList;

};
#endif // !SPRITESURFACE


