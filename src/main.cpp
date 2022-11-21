#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

int main(){
    SDL_Window *window;                    // Declare a pointer

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("failed to initailize %s\n", SDL_GetError());
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
	}

    //initialize the font stuff;
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Ascii Adventure",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    //create the renderer
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);

    TTF_Font* fontTypes = TTF_OpenFont("images/CollegiateBlackFLF.ttf", 20);

    std::cout << R"(        
         /\            (_|_)     /\      | |               | |                 
        /  \   ___  ___ _ _     /  \   __| |_   _____ _ __ | |_ _   _ _ __ ___ 
       / /\ \ / __|/ __| | |   / /\ \ / _` \ \ / / _ \ '_ \| __| | | | '__/ _ \
      / ____ \\__ \ (__| | |  / ____ \ (_| |\ V /  __/ | | | |_| |_| | | |  __/
     /_/    \_\___/\___|_|_| /_/    \_\__,_| \_/ \___|_| |_|\__|\__,_|_|  \___|
    )" << std::endl;

    std::string input;

    std::cout << "Select your option:" << std::endl;

    while(std::getline(std::cin, input)){

    
        // Check that the window was successfully created
        if (window == NULL) {
            // In the case that the window could not be made...
            printf("Could not create window: %s\n", SDL_GetError());
            return 1;
        }

        // The window is open: could enter program loop here (see SDL_PollEvent())

        //SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
        if(input == "start" || input == "s"){

        }else if(input == "load" || input == "l"){

        }else if(input == "quit" || input == "q"){
            // Close and destroy the window
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 0;
        }

    }

    // Clean up
    //SDL_Quit();

    return 0;
}