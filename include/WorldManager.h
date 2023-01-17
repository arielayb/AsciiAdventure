#ifndef _WORLDMANAGER_H
#define _WORLDMANAGER_H

#include "AbstractWorldManager.h"
#include <iostream>

class WorldManager : public AbstractWorldInterface {
    public:
        WorldManager();
        ~WorldManager(){};
        bool loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::vector<SDL_Rect> tileSet) override;

        //  set the level, items, and events
	    std::string levelfile;
};

#endif