#pragma once

#include <string>
#include <memory>
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "Definitions.h"

class Texture{

    public:
        //Initializes variables
        Texture();

        //Deallocates memory
        ~Texture();

        //Loads image at specified path
        bool load(SDL_Renderer* renderer, std::string path );
		bool load(SDL_Texture* texture);

        //Deallocates texture
        void free();

        //Renders texture at given point
		void render(SDL_Renderer* renderer, GAME_VEC position, SDL_Rect* clip = NULL);
		void render(SDL_Renderer* renderer, GAME_VEC position, GAME_FLT angle, SDL_Rect* clip = NULL);
		
		//Alternate render?
		//void render(SDL_Renderer* renderer, GAME_VEC position, GAME_FLT angle, SDL_Rect* clip = NULL );

        //Gets image dimensions
        int getWidth();
        int getHeight();

    private:

        //The actual hardware texture
		SDL_Texture* texture;

        //Image dimensions
        int width;
        int height;

};