#include <thread>
#include <Main.h>
#include <filesystem>

Main::Main(){

}

Main::~Main(){
    if(imgFac != nullptr){
        delete imgFac;
        imgFac = nullptr;
    }

    if(imgMgr != nullptr){
        delete imgMgr;
        imgMgr = nullptr;
    }
}

bool Main::mainLoop(){

    //create some attributes for openGL:
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    bool quit = false;
    startTitle_ = true;

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
        SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP // flags - see below
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

    TTF_Font* fontTypes = TTF_OpenFont("images/UbuntuMono-B.ttf", 16);

    std::string title = "Iron Age Stories";
    std::string startText = "New Game";
    std::string contText = "Continue";
    std::string exitText = "Exit Game";

    std::string input;

    //  load the textures
    imgFac = new ImageManagerFactory();
    imgMgr = imgFac->createImageManagerWithParams(image, renderer);

    // load image file
    // set the image folders
    // image loader manager 
    imgLoadFac = new ImageLoaderManagerFactory();
    imgLoadMgr = imgLoadFac->createImageLoaderManager();
    imgLoadMgr->setImagesFromFile("images/DawnLike/jsonImageFiles");

    //  give the font color
	SDL_Color fontColor = { 255, 255, 255 };

    //set title text
	SDL_Texture *titleTxt = imgMgr->loadFont(title, fontTypes, fontColor, renderer);
	SDL_Texture *startGameTxt = imgMgr->loadFont(startText, fontTypes, fontColor, renderer);
	SDL_Texture *continueTxt = imgMgr->loadFont(contText, fontTypes, fontColor, renderer);
	SDL_Texture *exitGameTxt = imgMgr->loadFont(exitText, fontTypes, fontColor, renderer);
	
    //load the images from the file
    std::string file = getImageFile("images/DawnLike/GUI/GUI0.png"); // get image file path
    SDL_Texture *img = imgMgr->loadTexture(file, img, renderer);
    SDL_Rect clip = getClipImage("images/DawnLike/GUI/GUI0.png_97"); // get sdl rect clip image

    // set or capture sprite arrow position
    int x = 880;
    int y = 500;
    bool newGame = false;
    bool contGame = false;
    bool contGameSelect = false;
    bool exit = false;

    // main loop for main menu title
    while(!quit){
        //clear the rendering so that we can re-render/update the screen
        // SDL_RenderClear(renderer);
        
        // imgMgr->renderTexture(880, 500, img, renderer, clip);

        while(SDL_PollEvent(&events)){
            if (events.type == SDL_QUIT || events.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }

            switch (startTitle_)
			{			
				case true:
				{	
					if (events.type == SDL_KEYDOWN){

                        if (events.key.keysym.sym == SDLK_UP && newGame == false)
                        {
                            // Mix_PlayChannel(-1, choice, 0);
                            x = 880;
                            y = 500;
                            imgMgr->renderTexture(x, y, img, renderer, clip);
                            contGame = false;
                            contGameSelect = false;
                            exit = true;
                            newGame = false;
                        }
                        else if (events.key.keysym.sym == SDLK_UP && contGame == false)
                        {
                            // Mix_PlayChannel(-1, choice, 0);
                            x = 880;
                            y = 555;
                            imgMgr->renderTexture(x, y, img, renderer, clip);
                            contGame = true;
                            contGameSelect = false;
                            exit = false;
                            newGame = false;
                        }
                        else if (events.key.keysym.sym == SDLK_DOWN && contGameSelect == false)
                        {
                            x = 880;
                            y = 555;
                            // Mix_PlayChannel(-1, choice, 0);
                            imgMgr->renderTexture(x, y, img, renderer, clip);
                            contGame = true;
                            contGameSelect = true;
                            newGame = false;
                            exit = false;
                        }
                        else if(events.key.keysym.sym == SDLK_DOWN && exit == false)
                        {
                            x = 880;
                            y = 610;
                            imgMgr->renderTexture(x, y, img, renderer, clip);
                            exit = false;
                            contGame = false;
                            contGameSelect = true;
                            newGame = true;
                        }else if (events.key.keysym.sym == SDLK_RETURN){
                            if (x == 880 && y == 500)
                            {
                                // Mix_PlayChannel(-1, success, 0);
                                
                                // menu = false;
                                //start = true;
                                                                
                                SDL_DestroyTexture(titleTxt);
                                SDL_DestroyTexture(startGameTxt);
                                SDL_DestroyTexture(continueTxt);
                            
                                //Stop the music 
                                //Mix_HaltMusic();
                            }
                            else if (x == 880 && y == 610)
                            {
                                //Stop the music 
                                //Mix_HaltMusic();
                                
                                quit = true;
                            }
                        }
                    }
                }
                break;
			}
		}

        if(startTitle_){
            //clear the rendering so that we can re-render/update the screen
            SDL_RenderClear(renderer);
            
            imgMgr->renderTexture(x, y, img, renderer, clip);

            //render the text of choices
            imgMgr->renderText(870, 400, titleTxt, renderer, nullptr);
            imgMgr->renderText(900, 500, startGameTxt, renderer, nullptr);
            imgMgr->renderText(900, 555, continueTxt, renderer, nullptr);
            imgMgr->renderText(900, 610, exitGameTxt, renderer, nullptr);

            //update the screen
            SDL_RenderPresent(renderer);
        }
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

std::string Main::getImageFile(std::string filePath){

    files = imgLoadMgr->getImagesFromFile(files);
    imageFileIter = files.find(filePath);

    //SDL_Rect clip;
    if ( imageFileIter == files.end() ){
       std::cout << "not found" << std::endl;
    }else{
        file_ = imageFileIter->first;
        std::cout << "filename: " << file_ << std::endl; 
    }

    return file_;
}

SDL_Rect Main::getClipImage(std::string imageClipPath){
    imgClips = imgLoadMgr->getPlayerClipImages(imgClips);
    iterClips = imgClips.find(imageClipPath);
    if ( iterClips == imgClips.end() ){
       std::cout << "not found" << std::endl;
    }else{
        clip_ = iterClips->second;
    }

    return clip_;
}

int main(){

    Main* main = new Main();

    std::thread mainMenu(&Main::mainLoop, main);
	mainMenu.join();

	//  start the main thread to draw the levels and events
	//launch.mainLoop();
	
	delete main;
    main = nullptr;

    return 0;
}