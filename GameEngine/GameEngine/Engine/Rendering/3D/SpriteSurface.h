#ifndef SPRITESURFACE_H
#define SPRITESURFACE_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Camera/Camera.h"
#include "Model.h"
#include "../../Graphics/TextureHandler.h"
#include "../../Graphics/MaterialHandler.h"

class SpriteSurface
{
public:
	SpriteSurface(std::string imagename_, glm::vec2 scale_, glm::vec2 angle_, glm::vec2 colour_);
	~SpriteSurface();

	void Draw(Camera* camera_, std::vector<glm::mat4> instances_);
	void OnDestroy();

	float GetWidth();
	float GetHeight();

	void SetWidth(float width_);
	void SetHeight(float height_);

private:
	void GenerateBuffers();
	
	std::string imagename;
	glm::vec2 scale;
	glm::vec2 angle;
	glm::vec2 colour;
	
	float angle, width, height;

	GLuint VAO, VBO;
};


#endif // !SPRITESURFACE_H
