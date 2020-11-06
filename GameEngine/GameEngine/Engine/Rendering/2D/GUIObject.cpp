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

void GUIObject::Draw(Camera* camera_)
{
	for (int i = 0; i < guicomponent.size(); i++)
	{
		guicomponent[i]->Draw(camera_, position);
	}
}

void GUIObject::SetTag(std::string tag_) 
{
	tag = tag_;
}