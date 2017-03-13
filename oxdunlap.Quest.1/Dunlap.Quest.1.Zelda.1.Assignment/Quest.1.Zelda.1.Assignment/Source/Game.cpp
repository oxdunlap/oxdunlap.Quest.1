#include "Game.h"

Game::Game(){
	gLibrary = NULL;
	aLibrary = NULL;
	gDevice = NULL;
	iDevice = NULL;
	timer = NULL;

	gameTime = 0.0f;

	view = NULL;
}

Game::~Game(){

}

//Constructs and Initializes ALL THE THINGS
bool Game::Initialize() {
	//Construct GraphicsDevice
	gDevice = std::unique_ptr<GraphicsDevice>(std::make_unique<GraphicsDevice>(SCREEN_WIDTH, SCREEN_HEIGHT));
	if (!gDevice->Initialize(false)) {	//windowed view
		std::cout << "Graphics Device could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	//Construct GameAssetLibrary
	gLibrary = std::unique_ptr<GameAssetLibrary>(std::make_unique<GameAssetLibrary>());
	if (!gLibrary->Initialize()){ 
		std::cout << "Graphics Asset Library could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		exit(1);
	};

	//Construct ArtAssetLibrary
	aLibrary = std::unique_ptr<ArtAssetLibrary>(std::make_unique<ArtAssetLibrary>());
	if (!aLibrary->Initialize(gDevice.get())) {
		std::cout << "Art Asset Library could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	//Construct InputDevice
	iDevice = std::unique_ptr<InputDevice>(std::make_unique<InputDevice>());
	if (!iDevice->Initialize()) {
		std::cout << "Input Device could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	//Construct Timer
	timer = std::unique_ptr<Timer>(std::make_unique<Timer>());
	if (!timer->Initialize()){
		std::cout << "Frame Timer could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	//Set gameTime
	gameTime = GAME_FPS;

	//Construct View
	view = std::unique_ptr<View>(std::make_unique<View>());
	if (!view->Initialize(iDevice.get(), 0.0, 0.0)) { //What should these floats be?
		std::cout << "View could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	return true;
}

void Game::Reset(){
	//Destroy view object
	//view->reset(); //makes it explode:?
	view->~View();
	//Clear objects vector
	objects.clear();
}

bool Game::LoadLevel(std::string levelConfigFile, std::string objectConfigFile){
	//***
	//objectConfig: uses ArtAssetLibrary 
	//***

		//Sets up the XML Documents based on the configFiles
		TiXmlDocument objectConfig(objectConfigFile.c_str());
		//Needs to catch when file is invalid?
		objectConfig.LoadFile();

		//Gets the first object element as child of the creature element
		TiXmlElement* objectElement = (objectConfig.FirstChildElement("Objects"))->FirstChildElement("Creature");

		//Checks each objectElement
		while (objectElement != NULL) {
			//Adds the new asset type to ArtAssetLibrart based on its unique identifier ("name")

			aLibrary->AddAsset(objectElement->Attribute("name"), objectElement->Attribute("sprite"));

			objectElement = objectElement->NextSiblingElement("Creature");
		}

	//***
	//levelConfig: uses GameAssetLibrary
	//***

		//Sets up the XML Documents based on the configFiles
		TiXmlDocument levelConfig(levelConfigFile.c_str());
		//Needs to catch when file is invalid?
		levelConfig.LoadFile();

		//Gets the first gameasset element as child of the level2 element
		//Why not just call it "Level"...?
		TiXmlElement* levelElement = (levelConfig.FirstChildElement("Level2"))->FirstChildElement("GameAsset");

		//Checks each levelElement
		while (levelElement != NULL) {
			//Stores new object of proper type into tempPtr
			auto tempPtr = gLibrary->Search(levelElement->Attribute("name"));

			//Initializes the new object with data from XML file
			tempPtr->Initialize(aLibrary->Search(levelElement->Attribute("name")), 
				gDevice.get(), iDevice.get(), atof(levelElement->Attribute("x")), 
				atof(levelElement->Attribute("y")), atof(levelElement->Attribute("angle"))); 

			objects.push_back(std::move(tempPtr));

			levelElement = levelElement->NextSiblingElement("GameAsset");
		}

	return true;
}

bool Game::Run(){
	//Starts the timer
	timer->start();

	//Updates all objects, returns false when GAME_QUIT is reached (see View)
	if (!Update()) { return false; }
	//Begins gDevice (clears renderer)
	gDevice->Begin();

	//Regulates framespeed
	timer->fpsRegulate();

	//Draws all objects
	Draw();
	//Updates the screen post-rendering
	gDevice->Present();

	return true; 
}

bool Game::Update(){

	//Iterates over each object and tells it to do it's Update() method
	for (auto objectsIter = objects.begin(); objectsIter != objects.end(); objectsIter++) {
		(*objectsIter)->Update(0.0); //What does this float need to do?
	}
	//Updates View and returns if not exiting
	return 	view->Update(gameTime);
}

void Game::Draw(){
	//Iterates over each object and tells it to do it's Draw() method
	for (auto objectsIter = objects.begin(); objectsIter != objects.end(); objectsIter++) {
		(*objectsIter)->Draw(0.0, view.get()); //What does this float need to do?
	}

}
