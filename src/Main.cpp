#include <thread>
#include <Main.h>
#include <ImageManagerFactory.h>
#include <ImageManager.h>
#include <AbstractImageManager.h>

Main::Main(){

}

Main::~Main(){

}

bool Main::mainLoop(){

    //create some attributes for openGL:
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    bool quit = false;
    bool menu = true;

//  to count the frame rate
	//Timer fps;

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
        "Iron Age Stories",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        1200,                               // width, in pixels
        920,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    //Initialize SDL_mixer 
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		quit = true;
	}

    //create the renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);

    //create the openGL context
	mainGLContext = SDL_GL_CreateContext(window);
	if (mainGLContext == NULL)
	{
		printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
	}

    TTF_Font* fontTypes = TTF_OpenFont("images/UbuntuMono-B.ttf", 50);

    std::string title = "Iron Age Stories";

    std::string input;

    //  load the textures
	// ImageManager load;
    ImageManagerFactory* imgFac = new ImageManagerFactory();
    AbstractImageManager* imgMgr = imgFac->createImageManager();

    //  give the font color
	SDL_Color fontColor = { 255, 255, 255 };

    std::string opt = "Select your option:";
	SDL_Texture *titleTxt = imgMgr->loadFont(title, fontTypes, fontColor, renderer);

    while(!quit){
        //clear the rendering so that we can re-render/update the screen
        SDL_RenderClear(renderer);
        
        //render the text of choices
        imgMgr->renderTexture(400, 400, titleTxt, renderer, NULL);


        while(SDL_PollEvent(&events)){
            //user game menu options below
            //user can quit the game on ESC key
            if (events.type == SDL_QUIT || events.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }
        }
        
        //SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
        if(input == "start" || input == "s"){

        }else if(input == "load" || input == "l"){

        }else if(input == "quit" || input == "q"){
            // Close and destroy the window
            SDL_DestroyWindow(window);
            SDL_Quit();
            quit = true;
            return quit;
        }

        //update the screen
        SDL_RenderPresent(renderer);
    }

    //  Deallocate surface
	SDL_DestroyTexture(image);

	//  destroy render
	SDL_DestroyRenderer(renderer);

	//  delete the openGL context
	SDL_GL_DeleteContext(mainGLContext);

    //  Destroy window
    SDL_DestroyWindow(window);
 
	//  close the font
	TTF_CloseFont(fontTypes);
	
	// SDL_FreeCursor(cursor);

	//  free the music pointers
	// Mix_FreeMusic(music);
	// Mix_FreeMusic(music2);
	// music = NULL;
	// music2 = NULL;

	// //  free soundFX pointers
	// Mix_FreeChunk(choice);
	// Mix_FreeChunk(success);
	// choice = NULL;
	// success = NULL;

	//  quit font/text system
	TTF_Quit();

	//  quit image systems
	IMG_Quit();

	//  quit the sound system
	Mix_Quit();

    // Clean up
    SDL_Quit();

    return quit;
}


int main(){

    Main* main = new Main();

    std::thread worldThread(&Main::mainLoop, main);
	worldThread.join();

	//  start the main thread to draw the levels and events
	//launch.mainLoop();
	
	delete main;
    main = nullptr;

    return 0;
}