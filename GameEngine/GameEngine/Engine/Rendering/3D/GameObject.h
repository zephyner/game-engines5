#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H 

#include "Model.h"
#include "Component.h"

class GameObject
{
public:

	GameObject(Model* model_, glm::vec3 position_ = glm::vec3());
	~GameObject();

	void Render(Camera* camera_);
	void Update(const float deltaTime_);

	glm::vec3 GetPosition() const;
	float GetAngle() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;
	BoundingBox GetBoundingBox();
	std::string GetTag() const;
	bool GetHit() const;
	
	void SetPosition(glm::vec3 Position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);
	void OnDestroy();

	//component add it here
	template <class T>
	void AddComponent();

	template <class T>
	T* GetComponent();

	template <class T>
	void RemoveComponent();

private:

	std::vector<Component*> component;

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

#endif // !GAMEOBJECT_H
