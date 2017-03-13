#pragma once

#include <memory>
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "Definitions.h"

class GraphicsDevice 
{
public:
	GraphicsDevice(Uint32, Uint32); //screen width and height
	~GraphicsDevice();

	bool Initialize(bool); //fullscreen or not
	bool ShutDown();
	void Begin();
	void Present();

	//Accessor Methods
	SDL_Renderer* GetRenderer();

private:
	SDL_Window* screen;
	SDL_Renderer* renderer;
};