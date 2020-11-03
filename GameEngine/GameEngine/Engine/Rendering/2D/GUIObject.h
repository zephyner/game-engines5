#ifndef GUIOBJECT_H
#define GUIOBJECT_H

#include <glew.h>
#include <glm/glm.hpp>
#include <string>
#include "GUIComponent.h"
#include "../../Core/Debug.h"
#include "../../Camera/Camera.h"

class GUIObject
{
public:

	GUIObject(glm::vec2 position_);
	~GUIObject();
	void OnDestroy();
	void Draw(Camera* camera_, glm::vec2 position_);
	void SetTag(std::string tag_);

	template <class T>
	void AddGUIComponent()
	{
		T* temp = new T();

		if (dynamic_cast<GUIComponent*>(temp) == nullptr)
		{
			Debug::Error("Object is not child of component: ", "GameObject.h", __LINE__);
			delete temp;
			temp = nullptr;
			return;
		}

		if (GetGUIComponent<T>() != nullptr)
		{
			Debug::Error("Object could not be gotten: ", "GameObject.h", __LINE__);
			delete temp;
			temp = nullptr;
			return;
		}

		temp->OnCreate(this);
		guicomponent.push_back(temp);
	}

	template <class T>
	T* GetGUIComponent()
	{
		for (GUIComponent* guicomp : guicomponent)
			if (dynamic_cast<T>(*guicomp))
				return (T*)guicomp;
		return nullptr;
	}

	template <class T>
	void RemoveGUIComponent()
	{
		for (int i = 0; i < guicomponent.size(); i++)
		{
			if (dynamic_cast<T*>(guicomponent[i]))
			{
				delete guicomponent[i];
				guicomponent[i] = nullptr;

				guicomponent.erase(guicomponent.begin() + i);

				break;
			}
		}
	}

private:
	std::vector<GUIComponent*> guicomponent;
	glm::vec2 position;
	std::string tag;
};

#endif // !GUIOBJECT_H


