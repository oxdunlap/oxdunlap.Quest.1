#include "ArtAssetLibrary.h"

ArtAssetLibrary::ArtAssetLibrary()
{
	gDevice = NULL;
}

ArtAssetLibrary::~ArtAssetLibrary()
{
}

bool ArtAssetLibrary::Initialize(GraphicsDevice* myGDevice){
	gDevice = myGDevice;
	return true;
}

bool ArtAssetLibrary::AddAsset(std::string key, std::string path){
	//Creates a temporary Texture
	std::shared_ptr<Texture> tempTexture(std::make_shared<Texture>());
	//Loads the Texture
	if (tempTexture->load(gDevice->GetRenderer(), path)) {
		library[key] = tempTexture;
		return true;
	}
	else {
		std::cout << "Texture failed to load. " << std::endl;
		exit(1);
	}

}

std::shared_ptr<Texture> ArtAssetLibrary::Search(std::string asset){
	//Searches for the asset name in the library, returns what it finds.
	//Doesnt use [] access because it would create a new element in the map if it doesn't find it.
	//try/catch for if asset isn't found
	try {
		return library.at(asset);
	} catch (...) {
		std::cout << "asset " << asset << " not found, throwing map.at exception error" << std::endl;
		exit(1);
	}
}