#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#ifndef _MAIN_H
#define _MAIN_H

class Main{

    public:
        Main();
        ~Main();

        bool mainLoop();

        //variables for the window
		SDL_Window* window;
 
        //  ceate player handler event
	    SDL_Event events;
    
        //these variables represent text for the fps and normal text displays.
		SDL_Texture* textFont;
		
		//set camera 
		SDL_Rect camera;

		//variable for rendering
		//SDL_Renderer* _renderer;

		//variable for font
		TTF_Font* fontTypes;

        //variable for rendering
		SDL_Renderer* renderer;

        //variables for the texture and image
		SDL_Texture* image;

    private:
        
		SDL_Texture* msgImage_;
};

#endif