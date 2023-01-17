#ifndef _ABSTRACTWORLDMANAGER_H
#define _ABSTRACTWORLDMANAGER_H

#include <SDL2/SDL_image.h>
#include <vector>

class AbstractWorldInterface {
    public:
        ~AbstractWorldInterface(){};
        virtual bool loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::vector<SDL_Rect> tileSet) = 0;


};

#endif