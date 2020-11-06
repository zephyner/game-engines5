#include "SceneGraph.h"

std::unique_ptr<SceneGraph> SceneGraph::sceneGraphInstance = nullptr;
std::map<std::string, GameObject*> SceneGraph::sceneGameObjects = std::map<std::string, GameObject*>();
std::map<std::string, GUIObject*> SceneGraph::sceneGUIObjects = std::map<std::string, GUIObject*>();
std::map<GLuint, std::vector<Model*>> SceneGraph::sceneModels = std::map<GLuint, std::vector<Model*>>();

SceneGraph::SceneGraph()
{

}
SceneGraph::~SceneGraph()
{
	OnDestroy();
}
SceneGraph* SceneGraph::GetInstance()
{
	if (sceneGraphInstance.get() == nullptr)
	{
		sceneGraphInstance.reset(new SceneGraph);
	}
	return sceneGraphInstance.get();
}

void SceneGraph::OnDestroy()
{
	if (sceneGameObjects.size() > 0)
	{
		for (auto go : sceneGameObjects)
		{
			delete go.second;
			go.second = nullptr;
		}
		sceneGameObjects.clear();
	}

	if (sceneModels.size() > 0)
	{
		for (auto entry : sceneModels)
		{
			if (entry.second.size() > 0)
			{
				for (auto m : entry.second)
				{
					delete m;
					m = nullptr;
				}
				entry.second.clear();
			}
		}
		sceneModels.clear();
	}

	if (sceneGUIObjects.size() > 0)
	{
		for (auto guiobj : sceneGUIObjects)
		{
			delete guiobj.second;
			guiobj.second = nullptr;
		}
		sceneGUIObjects.clear();
	}
}
void SceneGraph::AddModel(Model* model_)
{
	if (sceneModels.find(model_->GetShaderProgram()) == sceneModels.end())
	{
		std::vector<Model*> tmp = std::vector<Model*>();
		tmp.reserve(10);
		tmp.push_back(model_);
		sceneModels.insert(std::pair<GLuint, std::vector<Model*>>(model_->GetShaderProgram(), tmp));
	}
	else
	{
		sceneModels[model_->GetShaderProgram()].push_back(model_);
	}
}
void SceneGraph::AddGameObject(GameObject* go_, std::string tag_)
{
	if (tag_ == "")
	{
		std::string newName = "GameObject" + std::to_string(sceneGameObjects.size() + 1);
		go_->SetTag(newName);
		sceneGameObjects[newName] = go_;
	}

	else if (sceneGameObjects.find(tag_) == sceneGameObjects.end())
	{
		go_->SetTag(tag_);
		sceneGameObjects[tag_] = go_;
	}

	else
	{
		Debug::Error("Trying to add a game object with the tag " + tag_ + " that already exists", "SceneGraph.cpp", __LINE__);

		std::string newName = "GameObject" + std::to_string(sceneGameObjects.size() + 1);
		go_->SetTag(newName);
		sceneGameObjects[newName] = go_;
	}
	CollisionHandler::GetInstance()->AddObject(go_);
}

void SceneGraph::AddGUIObject(GUIObject* guiobj_, std::string tag_)
{
	if (tag_ == "")
	{
		std::string newName = "GUIObject" + std::to_string(sceneGUIObjects.size() + 1);
		guiobj_->SetTag(newName);
		sceneGUIObjects[newName] = guiobj_;
	}

	else if (sceneGUIObjects.find(tag_) == sceneGUIObjects.end())
	{
		guiobj_->SetTag(tag_);
		sceneGUIObjects[tag_] = guiobj_;
	}

	else
	{
		Debug::Error("Trying to add a GUI object with the tag " + tag_ + " that already exists", "SceneGraph.cpp", __LINE__);

		std::string newName = "GUIObject" + std::to_string(sceneGUIObjects.size() + 1);
		guiobj_->SetTag(newName);
		sceneGUIObjects[newName] = guiobj_;
	}
	
}

GameObject* SceneGraph::GetGameObject(std::string tag_)
{
	if (sceneGameObjects.find(tag_) != sceneGameObjects.end())
	{
		return sceneGameObjects[tag_];
	}
	return nullptr;
}

GUIObject* SceneGraph::GetGUIObject(std::string tag_)
{
	if (sceneGUIObjects.find(tag_) != sceneGUIObjects.end())
	{
		return sceneGUIObjects[tag_];
	}
	return nullptr;
}

void SceneGraph::Update(const float deltaTime_)
{
	for (auto go : sceneGameObjects)
	{
		go.second->Update(deltaTime_);
	}
}
void SceneGraph::Render(Camera* camera_)
{
	for (auto entry : sceneModels)
	{
		glUseProgram(entry.first);
		for (auto m : entry.second)
		{
			m->Render(camera_);
		}
	}
}

void SceneGraph::Draw()
{

}