#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Timer.h"
#include "GameAssetLibrary.h"
#include "ArtAssetLibrary.h"
#include "Object.h"

#include"tinyxml\tinystr.h"
#include"tinyxml\tinyxml.h"



class Game
{
public: 
	Game();
	~Game();

	bool Initialize(); //initializes or constructs all the members of the class
	void Reset(); //destroys the View object and all Objects stored in objects, and resets its size to zero;
	bool LoadLevel(std::string, std::string); 
						//constructs the View object, loads objects into
						//the ArtAssetLibray from an XML file, and loads from XML file (by both parsing the
						//XML and appropriate calls to the Art and Game Assets Libraries) and constructs all
						//Objects in the objects container
	bool Run(); // conducts a single frame of the game (i.e., Updating, Drawing, and frame timing)
	bool Update(); //calls the Update method of all Objects in objects
	void Draw(); //calls the Draw method of all Objects in objects

protected:
	std::unique_ptr<GameAssetLibrary> gLibrary; 
	std::unique_ptr<ArtAssetLibrary> aLibrary; 
	std::unique_ptr<GraphicsDevice> gDevice;
	std::unique_ptr<InputDevice> iDevice;

	std::unique_ptr<Timer> timer;
	GAME_FLT gameTime; 

	std::unique_ptr<View> view;
	std::vector<std::unique_ptr<Object>> objects;
};