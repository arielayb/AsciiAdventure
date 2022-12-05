#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include "AbstractImageLoaderManager.h"

#ifndef _IMAGELOADERMANAGER_H
#define _IMAGELOADERMANAGER_H

class ImageLoaderManager : public AbstractImageLoaderManager {
    public:
        ImageLoaderManager(){};
        ImageLoaderManager(SDL_Texture* image, std::string);
        ~ImageLoaderManager(){};

        virtual void setImagesFromFile(SDL_Texture *image, std::string folderPath);

        virtual std::unordered_map<std::string, SDL_Rect> getImagesFromFile(
                                                std::unordered_map<std::string, SDL_Rect> playerImages);

    private:
        SDL_Texture* image_;
        std::string folderPath_;
        std::unordered_map<std::string, SDL_Rect> playerImages_;
        std::vector<std::string> imageLists_;
};

#endif