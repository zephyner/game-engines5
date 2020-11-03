#include "GameScene.h"
// this is like test scene
GameScene::GameScene() : Scene()
{

}
GameScene::~GameScene()
{
	SceneGraph::GetInstance()->OnDestroy();
}

bool GameScene::OnCreate()
{
	Debug::Info("Creating Game Scene", "GameScene.cpp", __LINE__);


	CoreEngine::GetInstance()->SetCamera(new Camera);
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	CollisionHandler::GetInstance()->OnCreate();
	//Light Source
	CoreEngine::GetInstance()->GetCamera()->AddLightSources(new LightSource(glm::vec3(0.0f, 0.0f, 2.0f), 1.0f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));

	//apple model
	Model* model = new Model("./Resources/Models/Apple.obj", "./Resources/Materials/Apple.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	Model* model1 = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	SceneGraph::GetInstance()->AddModel(model);
	SceneGraph::GetInstance()->AddModel(model1);
	//add apple gameobject
	GameObject* apple = new GameObject(model);
	GameObject* dice = new GameObject(model1, glm::vec3(0.5f, -0.5f, 0.0f));
	apple->SetScale(glm::vec3(0.5f));
	SceneGraph::GetInstance()->AddGameObject(apple, "apple");
	SceneGraph::GetInstance()->AddGameObject(dice, "dice");

	return true;
}
void GameScene::Update(const float deltaTime_)
{
	SceneGraph::GetInstance()->Update(deltaTime_);
}
void GameScene::Render()
{
	SceneGraph::GetInstance()->Render(CoreEngine::GetInstance()->GetCamera());
}

void GameScene::Draw()
{

}

