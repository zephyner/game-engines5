#ifndef GUICOMPONENT_H
#define GUICOMPONENT_H

#include <vector>
#include <iostream>

class GameObject;

class GUIComponent
{
public:

	GUIComponent();
	virtual ~GUIComponent();
	virtual bool OnCreate(GameObject* gameObject_);
	virtual void Update(const float deltaTime_);
	virtual void Draw();
	virtual void FindContainingPoint();

protected:
	GameObject* gameObject;
};
#endif // !GUICOMPONENT_H



