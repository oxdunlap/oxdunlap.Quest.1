#ifndef ARTASSETLIBRARY_H
#define ARTASSETLIBRARY_H

#include <string>
#include <map>
#include <memory>
#include <iostream>	
#include "GraphicsDevice.h"
#include "Texture.h"

class ArtAssetLibrary
{
public:
	ArtAssetLibrary();
	~ArtAssetLibrary();

	bool Initialize(GraphicsDevice*);
	bool AddAsset(std::string key, std::string path);
	std::shared_ptr<Texture> Search(std::string);

protected:
	std::map<std::string, std::shared_ptr<Texture>> library;
	GraphicsDevice* gDevice;

};

#endif