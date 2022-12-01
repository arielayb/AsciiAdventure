#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_events.h>

#ifndef _MAIN_H
#define _MAIN_H

class Main{

    public:
        Main();
        ~Main();

        bool mainLoop();

        //variables for the window
		SDL_Window* window = NULL;
 
		SDL_GLContext glContext = NULL;

        //  ceate player handler event
	    SDL_Event events;
    
        //these variables represent text for the fps and normal text displays.
		SDL_Texture* textFont = NULL;
		
		//set camera 
		SDL_Rect camera;

		//variable for rendering
		//SDL_Renderer* _renderer;

		//variable for font
		TTF_Font* fontTypes = NULL;

        //variable for rendering
		SDL_Renderer* renderer = NULL;

        //variables for the texture and image
		SDL_Texture* image = NULL;

    private:
        
		SDL_Texture* msgImage_ = NULL;
};

#endif