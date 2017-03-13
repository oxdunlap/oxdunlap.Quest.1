#include "GraphicsDevice.h"

GraphicsDevice::GraphicsDevice(Uint32 width, Uint32 height) 
{
	screen = NULL;
	renderer = NULL;

	//See:Initialize
}

GraphicsDevice::~GraphicsDevice()
{
	//Checks to see if Shutdown fails
	if (!ShutDown()) {
		std::cout << "SDL could not shut down! SDL_Error: " << SDL_GetError() << std::endl;
		exit(1);
	}
}

bool GraphicsDevice::Initialize(bool fullscreen)
{
	//Initialize the SDL systems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//Initialize SDL_Image subsystems
	if (!IMG_INIT_PNG) {
		std::cout << "SDL_image could not initialize! SDL_Error: " << IMG_GetError() << std::endl;
		return false;
	}

	//Assigns the screen based on fullscreen arg
	if (fullscreen) {
		screen = SDL_CreateWindow("Zelda Quest 1",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
	}
	else {
		screen = SDL_CreateWindow("Zelda Quest 1",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	}

	//Constructs the renderer using hardware acceleration
	renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}

	//If it made it this far, it initialized properly.
	return true;
}

bool GraphicsDevice::ShutDown()
{
	//Free the window
	SDL_DestroyWindow(screen);
	screen = NULL;

	//Free the renderer
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	IMG_Quit(); //quits IMG subsystems
	SDL_Quit();	//quits SDL
	return true;
}

void GraphicsDevice::Begin()
{
	SDL_RenderClear(renderer);
}

void GraphicsDevice::Present()
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* GraphicsDevice::GetRenderer()
{
	return renderer;
}
