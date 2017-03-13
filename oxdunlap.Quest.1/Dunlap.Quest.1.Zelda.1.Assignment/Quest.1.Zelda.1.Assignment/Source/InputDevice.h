#pragma once

#include <memory>
#include <iostream>

#include "Definitions.h"
#include "SDL.h"

class InputDevice
{
public:
	InputDevice();
	~InputDevice();

	bool Initialize(); //initializes the InputDevice by creating the “event” uniquepointer
	GAME_EVENT GetEvent(); //polls SDL for the latest event and calls “Translate” to convert it to a game event

private:
	GAME_EVENT Translate(); //this private method translates SDL_Event information into GAME_EVENT type information (see Definitions.h)

protected:
	std::unique_ptr<SDL_Event> event;
};