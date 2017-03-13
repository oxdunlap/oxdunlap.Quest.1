#include "InputDevice.h"

InputDevice::InputDevice(){

}

InputDevice::~InputDevice()
{
}

bool InputDevice::Initialize(){
	event = std::unique_ptr<SDL_Event>(std::make_unique<SDL_Event>());
	if (!event)
	{
		std::cout << "SDL Event could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		exit(1);
	}
	return true;
}

GAME_EVENT InputDevice::GetEvent(){
	SDL_PollEvent(event.get());
	return Translate();
}

GAME_EVENT InputDevice::Translate(){
	//NOTE: doesn't handle multiple simultaneous button presses very well. 
	//To do this, use a map with bool flags
	switch (event->type) {
	case SDL_KEYDOWN:
		switch (event->key.keysym.sym) {
		case SDLK_ESCAPE:
			return GAME_QUIT;
			break;
		case SDLK_LEFT:
			return GAME_LEFT;
			break;
		case SDLK_RIGHT:
			return GAME_RIGHT;
			break;
		case SDLK_UP:
			return GAME_UP;
			break;
		case SDLK_DOWN:
			return GAME_DOWN;
			break;
		default:
			return GAME_NA;
			break;
		}
	default:
		break;
	}
}