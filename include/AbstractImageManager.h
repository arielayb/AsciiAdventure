#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#ifndef _ABSTRACTIMAGEMANAGER_H
#define _ABSTRACTIMAGEMANAGER_H

class AbstractImageManager{
    public:
    ~AbstractImageManager(){};
    //load the texture and font
    virtual SDL_Texture* loadTexture(std::string file, SDL_Texture *textures, SDL_Renderer *render) = 0;
    virtual SDL_Texture* loadFont(std::string time, TTF_Font* fontType, SDL_Color fontColor, SDL_Renderer* render) = 0;
    //render image
    virtual bool renderTexture(float x, float y, SDL_Texture* image, SDL_Renderer* render, SDL_Rect clip) = 0;
    //render text
    virtual bool renderText(float x, float y, SDL_Texture* image, SDL_Renderer* render, SDL_Rect* clip = nullptr) = 0;
};

#endif