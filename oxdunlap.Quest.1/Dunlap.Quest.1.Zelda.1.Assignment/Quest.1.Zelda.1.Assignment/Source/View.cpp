//Modified from:	View.cpp by Sean Orme		Magic Mage

#include <iostream>
#include "View.h"

View::View()
{
	iDevice = NULL;

}

View::~View()
{
	
}

//**************************************
//Set initial values
bool View::Initialize(InputDevice* iDevice, GAME_FLT x, GAME_FLT y)
//**************************************
{
	this -> iDevice = iDevice;
	position.x = x;
	position.y = y;
	center = position;
	return true;
}

//**************************************
//Responds to game events
bool View::Update(GAME_FLT gameTime)
//**************************************
{ 	
	center = position;
	//Checks for input, responds accordingly
	//NOTE: doesn't handle multiple simultaneous button presses very well. 
	//To do this, use a series of if statements, not a switch (or if/else)
	switch (iDevice->GetEvent()) {
	case GAME_QUIT:
		return false;
		break;
	case GAME_LEFT:
		setX(position.x - 1);
		break;
	case GAME_RIGHT:
		setX(position.x + 1);
		break;
	case GAME_UP:
		setY(position.y + 1);
		break;
	case GAME_DOWN:
		setY(position.y - 1);
		break;
	default: //GAME_NA
		break;
	}
	return true;
}

//**************************************
//print view data
void View::Print()
//**************************************
{
	std::cout << "*****VIEW******" << std::endl <<
		"View X: " << position.x << std::endl <<
		"View Y: " << position.y << std:: endl <<
		std::endl;
}