//Modified from:	View.h by Sean Orme		Magic Mage

#pragma once

#include "Definitions.h"
#include "InputDevice.h"


class View{
public:
	View();
	~View();

	bool Initialize(InputDevice* iDevice, GAME_FLT x, GAME_FLT y);
	bool Update(GAME_FLT gameTime);
	void Print();
	
	GAME_VEC getPosition(){return position;}

	//Accessor Methods
	void setPosition(GAME_VEC position){this -> position = position;}
	void setX(GAME_FLT x){this -> position.x = x;}
	void setY(GAME_FLT y){this -> position.y = y;}

private:
	InputDevice* iDevice;
	GAME_VEC position;
	GAME_VEC center; 
};