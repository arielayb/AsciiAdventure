#include <fstream>
#include <ImageLoaderManager.h>
#include <json.hpp>
#include <iostream>
#include <filesystem>

using json = nlohmann::json;

ImageLoaderManager::ImageLoaderManager(SDL_Texture* image, std::string folderPath){
    image_ = image;
    folderPath_ = folderPath;
}


void ImageLoaderManager::setImagesFromFile(SDL_Texture *image, std::string folderPath)
{
    for (const auto & entry : std::filesystem::directory_iterator(folderPath)){
        //std::cout << entry.path() << std::endl;
    
        std::ifstream jsonFile(entry.path());

        json data = json::parse(jsonFile);
        int size = data["meta"]["slices"].size();
        std::cout << "size:" << size << std::endl;

        for(int i = 0; i < size; i++){
            std::string name =  data["meta"]["slices"][i]["name"];
            std::cout << "name:" << name << std::endl;

            std::cout << data["meta"]["slices"][i]["keys"][0]["bounds"] << std::endl;
            std::cout << data["meta"]["slices"][i]["keys"][0]["bounds"]["h"] << std::endl;

            playerImages_[name].x = data["meta"]["slices"][i]["keys"][0]["bounds"]["x"]; 
            playerImages_[name].y = data["meta"]["slices"][i]["keys"][0]["bounds"]["y"]; 
            playerImages_[name].w = data["meta"]["slices"][i]["keys"][0]["bounds"]["w"]; 
            playerImages_[name].h = data["meta"]["slices"][i]["keys"][0]["bounds"]["h"]; 
        }   
    }
}

std::unordered_map<std::string, SDL_Rect> ImageLoaderManager::getImagesFromFile(
                                                std::unordered_map<std::string, SDL_Rect> playerImages){
    playerImages = playerImages_;
    return playerImages;
}
