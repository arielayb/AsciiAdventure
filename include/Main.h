#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_events.h>
#include <AbstractImageManagerFactory.h>
#include <AbstractImageLoaderManagerFactory.h>
#include <ImageLoaderManagerFactory.h>
#include <ImageManagerFactory.h>

#ifndef _MAIN_H
#define _MAIN_H

class Main{

    public:
        Main();
        ~Main();

        bool mainLoop();
		std::string getImageFile();
		SDL_Rect getClipImage();

        //variables for the window
		SDL_Window* window = NULL;
 
		//variables to load openGL stuff...
		SDL_GLContext mainGLContext;

        //  ceate player handler event
	    SDL_Event events;

		std::unordered_map<std::string, SDL_Rect> imgClips; //container for sdl rect images.
		std::unordered_map<std::string, int> files; // container for image files.

    	std::unordered_map<std::string, SDL_Rect>::const_iterator iterClips; //iterator for sdl rect container.
		std::unordered_map<std::string, int>::const_iterator imageFileIter; //iterator for image file container.

        //these variables represent text for the fps and normal text displays.
		SDL_Texture* textFont = NULL;
		
		//set camera 
		SDL_Rect camera;

		//variable for font
		TTF_Font* fontTypes = NULL;

        //variable for rendering
		SDL_Renderer* renderer = NULL;

        //variables for the texture and image
		SDL_Texture* image = NULL;

		ImageManagerFactory* imgFac = nullptr;
    	AbstractImageManager* imgMgr = nullptr;
		ImageLoaderManagerFactory* imgLoadFac = nullptr;
    	AbstractImageLoaderManager* imgLoadMgr = nullptr;

    private:
        
		SDL_Texture* msgImage_ = NULL;
		bool startTitle_;
		std::vector<SDL_Rect> clipList_;
		std::string file_;
		SDL_Rect clip_;  		//set clipping for image
};

#endif