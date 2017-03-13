#pragma once

#include <memory>
#include <iostream>
#include <random>
#include <algorithm>

#include "SDL.h"
#include "Texture.h"
#include "InputDevice.h"
#include "GraphicsDevice.h"
#include "Definitions.h"
#include "View.h"

//not #include to prevent circular reference?
//class Texture;

class Object
{
public:
	Object();
	~Object();

	bool Initialize (std::shared_ptr<Texture>, GraphicsDevice*, InputDevice*, GAME_FLT, GAME_FLT, GAME_FLT); 
	virtual void Update(GAME_FLT) = 0;
	void Draw(GAME_FLT, View*);

protected:
	GraphicsDevice* gDevice;
	InputDevice* iDevice;
	std::shared_ptr<Texture> texture; 
	GAME_VEC position;
	GAME_VEC startPosition;
	GAME_FLT angle;

	float randParam; //Used to give the objects their behaviors. 
};