#include "Engine/Core/CoreEngine.h"
#include "Game/Game1.h"
#include "json.hpp"


int main(int argc, char* argv[])
{
	CoreEngine::GetInstance()->SetGameInterFace(new Game1);
	
	//checking window is running good;
	if (!CoreEngine::GetInstance()->OnCreate("GAME ENGINE", 1280, 720))
	{
		std::cout << "Engine failed to be created " << std::endl;
		return 0;
	}
	
	CoreEngine::GetInstance()->Run();
	
	std::ifstream file("./Resources/Test.json");
	nlohmann::json j;
	file >> j;
	file.close();
	int id = j["list"]["object"]["id"].get<int>();
	std::string objectname = j["list"]["object"]["objectname"].get < std::string>();
	std::string rendertype = j["list"]["object"]["rendertype"].get < std::string>();

	std::cout << "object name: " << objectname << std::endl;
	std::cout << "render type: " << rendertype << std::endl;

	getchar();

	return 0;
}
