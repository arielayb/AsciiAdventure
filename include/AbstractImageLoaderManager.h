#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>
#include <vector>

#ifndef _ABSTRACTIMAGELOADERMANAGER_H
#define _ABSTRACTIMAGELOADERMANAGER_H

class AbstractImageLoaderManager {
    public:
        ~AbstractImageLoaderManager(){};

        virtual void setImagesFromFile(std::string folderPath) = 0;

        virtual std::unordered_map<std::string, int> getImagesFromFile(
                                                std::unordered_map<std::string, int> playerImages) = 0;
        virtual std::unordered_map<std::string, SDL_Rect> getPlayerClipImages(
                                                std::unordered_map<std::string, SDL_Rect> playerImages) = 0;
        virtual std::vector<SDL_Rect> getClipList() = 0; 
        virtual void setClipList(std::vector<SDL_Rect> imageClips) = 0; 
};

#endif