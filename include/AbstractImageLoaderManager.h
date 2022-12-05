#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>

#ifndef _ABSTRACTIMAGELOADERMANAGER_H
#define _ABSTRACTIMAGELOADERMANAGER_H

class AbstractImageLoaderManager {
    public:
        ~AbstractImageLoaderManager(){};

        virtual void setImagesFromFile(SDL_Texture *image, std::string folderPath) = 0;

        virtual std::unordered_map<std::string, SDL_Rect> getImagesFromFile(
                                                std::unordered_map<std::string, SDL_Rect> playerImages) = 0; 
};

#endif