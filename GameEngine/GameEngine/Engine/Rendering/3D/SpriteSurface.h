#ifndef SPRITESURFACE
#define SPRITESURFACE

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Camera/Camera.h"
#include "../../Graphics/MaterialHandler.h"


//struct is public by default
struct Vertex2D
{
	glm::vec2 position;
	glm::vec2 textCoords;
};

class SpriteSurface
{
public:
	SpriteSurface(std::string imageName_, glm::vec2 scale_, float angle_, glm::vec4 colour_);
	~SpriteSurface();

	void Draw(Camera* camera_, std::vector<glm::mat4> instances_);

	float GetWidth();
	float GetHeight();

private:
	void GenerateBuffers();

	std::string imageName;
	glm::vec2 scale;
	float angle, width, height;

};
#endif // !SPRITESURFACE


