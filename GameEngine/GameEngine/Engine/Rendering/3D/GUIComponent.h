#ifndef GUICOMPONENT_H
#define GUICOMPONENT_H

#include <vector>
#include <iostream>

//forward declaration
class GUIObject;

class GUIComponent
{
public:

	GUIComponent();
	virtual ~GUIComponent();
	virtual bool OnCreate(GUIObject* guiObject_);
	virtual void Update(const float deltaTime_);

	virtual void Draw();
	virtual bool FindingContainingPoint();

protected:
	GUIObject* guiObject;
};
#endif // !GUICOMPONENT_H