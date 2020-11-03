#include "GUIImageComponent.h"

GUIImageComponent::GUIImageComponent() : offset(glm::vec2()), sprite(nullptr)
{

}

GUIImageComponent::~GUIImageComponent()
{
	sprite = nullptr;
	delete sprite;
}

bool GUIImageComponent::OnCreate(std::string imageName_, glm::vec2 offset_, glm::vec2 scale_, float angle_, glm::vec4 tintColour_)
{
	//saving offset as parameter
	offset = offset_;
	//creating spritesurface object
	sprite = new SpriteSurface(imageName_, scale_, angle_, tintColour_);
}

void GUIImageComponent::Draw(Camera* camera_, glm::vec2 position_)
{

}

void GUIImageComponent::FindContainingPoint(glm::vec2 point_)
{
	glm::vec2 minVert;
	int width = sprite->GetWidth();
	int height = sprite->GetHeight();

	//check to see if image is there, similar to bounding box

	if (point_.x >= 0 + width
		& point_.y >= 0 + height)
	{
		std::cout << "Hit" << std::endl;
	}
	return;
}

