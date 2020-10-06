#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <iostream>

//forward declaration
class GameObject;

class Component
{
public:

	Component() { gameObject = nullptr; }
	virtual ~Component() { gameObject = nullptr; }
	virtual bool OnCreate(GameObject*) = 0;
	virtual void Update(const float deltaTime_) = 0;

protected:
	GameObject* gameObject;

};
#endif // !COMPONENT_H
