#ifndef GUIOBJECT_H
#define GUIOBJECT_H

#include "Model.h"
#include "GUIComponent.h"

class GUIObject
{
public:
	GUIObject(Model* model_, glm::vec3 position_ = glm::vec3());
	~GUIObject();

	void Draw();
	void Update();

	template <class T>
	void AddGUIComponent()
	{
		T* temp = new T();

		if (dynamic_cast<guiComponent*>(temp) == nullptr)
		{
			Debug::Error("Object is not child of component: ", "GameObject.h", __LINE__);
			delete temp;
			temp = nullptr;
			return;
		}

		if (GetComponent<T>() != nullptr)
		{
			Debug::Error("Object could not be gotten: ", "GameObject.h", __LINE__);
			delete temp;
			temp = nullptr;
			return;
		}

		temp->OnCreate(this);
		guiComponent.push_back(temp);
	}

	template <class T>
	T* GetGUIComponent()
	{
		for (guiComponent* guicomp : guiComponent)
			if (dynamic_cast<T>(*guicomp))
				return (T*)guicomp;
		return nullptr;
	}

	template <class T>
	void RemoveGUIComponent()
	{
		for (int i = 0; i < guiComponent.size(); i++)
		{
			if (dynamic_cast<T*>(guiComponent[i]))
			{
				delete guiComponent[i];
				guiComponent[i] = nullptr;

				guiComponent.erase(component.begin() + i);

				break;
			}
		}
	}

private:
	std::vector<GUIComponent*> guiComponent;

	Model* model;
	glm::vec3 position;
	float angle;
	glm::vec3 rotation;
	glm::vec3 scale;
	int modelInstance;

	BoundingBox box;

	std::string tag;
	bool hit;
};


#endif // !GUIOBJECT_H



