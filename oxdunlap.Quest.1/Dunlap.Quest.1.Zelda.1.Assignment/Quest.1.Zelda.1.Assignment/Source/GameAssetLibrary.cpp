#include "GameAssetLibrary.h"

GameAssetLibrary::GameAssetLibrary()
{
}

GameAssetLibrary::~GameAssetLibrary()
{
}

bool GameAssetLibrary::Initialize()
{
	//Populates library with all GameFactory types
	library["Blue Leever Factory"] = std::unique_ptr<ObjectFactory>(std::make_unique<BlueLeeverFactory>());
	library["Blue Octorok Factory"] = std::unique_ptr<ObjectFactory>(std::make_unique<BlueOctorokFactory>());
	library["Red Leever Factory"] = std::unique_ptr<ObjectFactory>(std::make_unique<RedLeeverFactory>());
	library["Red Octorok Factory"] = std::unique_ptr<ObjectFactory>(std::make_unique<RedOctorokFactory>());
	return true;
}

std::unique_ptr<Object> GameAssetLibrary::Search(std::string objectType)
{
	//Returns a pointer to a new object, created by the matching factory
	//The ending is to make it consistently convert from the XML file to the proper factory, which is named differently
	auto newObject = library.at(objectType + " Factory")->create();
	return newObject;
}
