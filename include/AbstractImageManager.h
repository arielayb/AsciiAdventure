#include "AbstractImageManagerFactory.h"

#ifndef _ABSTRACTIMAGEMANAGER_H
#define _ABSTRACTIMAGEMANAGER_H

class AbstractImageManager{
    public:
    ~AbstractImageManager();
    //load the texture and font
    virtual SDL_Texture* loadTexture(std::string file, SDL_Texture *textures, SDL_Renderer *render) = 0;
    virtual SDL_Texture* loadFont(std::string time, TTF_Font* fontType, SDL_Color fontColor, SDL_Renderer* render) = 0;
    //render image
    virtual bool renderTexture(float x, float y, SDL_Texture* image = NULL, SDL_Renderer* render = NULL, SDL_Rect* clip = NULL) = 0;
};

#endif