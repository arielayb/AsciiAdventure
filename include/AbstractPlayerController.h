#ifndef _ABSTRACTPLAYERCONTROLLER_H
#define _ABSTRACTPLAYERCONTROLLER_H

#include <SDL2/SDL_events.h>

class AbstractPlayerController{
    public:
        ~AbstractPlayerController(){};
        virtual void playerInput(SDL_Event events) = 0;  
        virtual bool checkingCollisions(SDL_Rect playerBox, SDL_Rect object) = 0;
        virtual void collisionManagement(SDL_Rect playerBox) = 0;
};

#endif