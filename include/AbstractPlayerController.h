#ifndef _ABSTRACTPLAYERCONTROLLER_H
#define _ABSTRACTPLAYERCONTROLLER_H

#include <SDL2/SDL_events.h>

class AbstractPlayerController{
    public:
        ~AbstractPlayerController(){};
        virtual void playerInput(SDL_Event events) = 0;  
};

#endif