#include <fstream>
#include <ImageLoaderManager.h>
#include <json.hpp>
#include <iostream>

using json = nlohmann::json;

ImageLoaderManager::ImageLoaderManager(SDL_Texture* image, std::string filePath){
    image_ = image;
    filePath_ = filePath;
}


void ImageLoaderManager::setImagesFromFile(SDL_Texture *image, std::string filePath)
{
    // std::ifstream jsonFile("../images/DawnLike/Characters/Player1.json");
    std::ifstream jsonFile(filePath);

    json data = json::parse(jsonFile);
    //std::string x = data.value("x", "not found");
    //std::string y = data.value("y", "not found");
    int size = data["meta"]["slices"].size();
    // std::string name = data["meta"]["slices"]["name"];
    std::cout << "size:" << size << std::endl;
    // std::cout << "name:" << name << std::endl;

    // special iterator member functions for objects
    // for (json::iterator it = data.begin(); it != data.end(); ++it) {
    //     // std::cout << it.key() << " : " << it.value() << "\n";
    //     if(it.key() == "name"){
    //         std::cout << "value: " << it.value() << std::endl;
    //     }
    // }


    for(int i = 0; i < size; i++){
        std::string name = data["meta"]["slices"][0][0];
        std::string x = data.value("x", "not found");
        std::string y = data.value("y", "not found");
        std::string w = data.value("w", "not found");
        std::string h = data.value("h", "not found");
        std::cout << "name:" << name << std::endl;

        playerImages_[name].x = std::stoi(x); 
        playerImages_[name].y = std::stoi(y);  
        playerImages_[name].w = std::stoi(w);  
        playerImages_[name].h = std::stoi(h);  
    }
}

std::unordered_map<std::string, SDL_Rect> ImageLoaderManager::getImagesFromFile(
                                                std::unordered_map<std::string, SDL_Rect> playerImages){
    playerImages = playerImages_;
    return playerImages;
}
