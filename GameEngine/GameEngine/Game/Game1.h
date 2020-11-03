#ifndef GAME1_H
#define GAME1_H

#include "../Engine/Core/CoreEngine.h"
#include "Scenes/StartScene.h"
#include "Scenes/GameScene.h"

class Game1 : public GameInterFace
{
public:

	Game1();
	virtual ~Game1();

	virtual bool OnCreate();
	virtual void Update(const float deltaTime_);
	virtual void Render();
	//draw function for gui update
	virtual void Draw();
	virtual void OnDestroy();

private:
	int currentSceneNum;
	Scene* currentScene;
	void BuildScene();

};
#endif //!GAME1_H
