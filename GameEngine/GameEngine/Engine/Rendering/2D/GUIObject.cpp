#include "GUIObject.h"

GUIObject::GUIObject(glm::vec2 position_)
{
	position = position_;
}

GUIObject::~GUIObject()
{
	OnDestroy();
}

void GUIObject::OnDestroy()
{
	guicomponent.clear();
}

void GUIObject::Draw(Camera* camera_, glm::vec2 position_)
{
	
}

void GUIObject::SetTag(std::string tag_) 
{
	tag = tag_;
}