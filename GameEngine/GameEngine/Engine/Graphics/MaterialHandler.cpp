#include "MaterialHandler.h"

std::unique_ptr<MaterialHandler> MaterialHandler::MaterialInstance = nullptr;
std::vector<Material> MaterialHandler::materials = std::vector<Material>();


MaterialHandler::MaterialHandler()
{
	materials.reserve(10);
}
MaterialHandler::~MaterialHandler()
{
	OnDestroy();
}
MaterialHandler* MaterialHandler::GetInstance()
{
	if (MaterialInstance.get() == nullptr)
	{
		MaterialInstance.reset(new MaterialHandler);
	}
	return MaterialInstance.get();
}
void MaterialHandler::AddMaterial(Material mat_)
{
	materials.push_back(mat_);
}

const Material MaterialHandler::GetMaterial(const std::string& matName_)
{
	for (auto mats : materials)
	{
		if (mats.name == matName_)
		{
			return mats;
		}
	}
	return Material();
}
void MaterialHandler::OnDestroy()
{
	if (materials.size() > 0)
	{
		materials.clear();
	}
}
