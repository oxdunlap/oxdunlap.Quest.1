#pragma once

#include <memory>
#include <map>

#include "BlueLeeverFactory.h"
#include "BlueOctorokFactory.h"
#include "RedLeeverFactory.h"
#include "RedOctorokFactory.h"


class GameAssetLibrary
{
public:
	GameAssetLibrary();
	~GameAssetLibrary();

	bool Initialize();

	std::unique_ptr<Object> Search(std::string);

protected:
	std::map<std::string, std::unique_ptr<ObjectFactory>> library;

};