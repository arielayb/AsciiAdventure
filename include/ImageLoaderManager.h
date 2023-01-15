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
        ~ImageLoaderManager();

        virtual void setImagesFromFile(std::string folderPath);

        virtual std::unordered_map<std::string, int> getImagesFromFile(
                                                std::unordered_map<std::string, int> playerImages);
        virtual std::unordered_map<std::string, SDL_Rect> getPlayerClipImages(
                                                std::unordered_map<std::string, SDL_Rect> playerClipImages);
        virtual std::vector<SDL_Rect> getClipList(); 
        virtual void setClipList(std::vector<SDL_Rect> imageClips);

    private:
        SDL_Texture* image_ = nullptr;
        std::string folderPath_;
        std::unordered_map<std::string, SDL_Rect> playerClipImages_;  
        std::unordered_map<std::string, int> fileImages_;
        std::vector<std::string> jsonFiles_;
        std::vector<SDL_Rect> clipLists_;
};

#endif