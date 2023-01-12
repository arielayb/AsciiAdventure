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

ImageLoaderManager::~ImageLoaderManager(){
    if(image_ != nullptr){
        SDL_DestroyTexture(image_);
    }
}

void ImageLoaderManager::setImagesFromFile(std::string folderPath)
{
    for (const auto & entry : std::filesystem::directory_iterator(folderPath)){    
        std::ifstream jsonFile(entry.path());

        json data = json::parse(jsonFile);
        int size = data["meta"]["slices"].size();
        
        std::string imageName = data["meta"]["slices"][0]["name"];
        std::stringstream test(imageName);
        std::string filename;
        std::getline(test, filename, '_');
        std::cout << "filename: " << filename << std::endl;

        fileImages_[filename] = size;
        std::vector<std::string>::iterator iter = jsonFiles_.begin();
        jsonFiles_.insert(iter, entry.path());
    }

    std::unordered_map<std::string, int>::const_iterator iter = fileImages_.begin(); 
    int jsonFilesize = jsonFiles_.size();
    int k = 0;
    //int size = fileImages_.size();
    for (iter; iter != fileImages_.end(); iter++){
        std::cout << "iter: " << iter->second << std::endl;   
        for(int j = 0; j < iter->second; j++){
            std::ifstream jsonFile(jsonFiles_[k]);
            json data = json::parse(jsonFile);
            
            std::string name = data["meta"]["slices"][j]["name"];
            std::cout << "name:" << name << std::endl;

            std::cout << data["meta"]["slices"][j]["keys"][0]["bounds"] << std::endl;

            playerClipImages_[name].x = data["meta"]["slices"][j]["keys"][0]["bounds"]["x"]; 
            playerClipImages_[name].y = data["meta"]["slices"][j]["keys"][0]["bounds"]["y"]; 
            playerClipImages_[name].w = data["meta"]["slices"][j]["keys"][0]["bounds"]["w"]; 
            playerClipImages_[name].h = data["meta"]["slices"][j]["keys"][0]["bounds"]["h"];

            clipLists_.push_back(playerClipImages_[name]); 
        }
        k+=1;
    }
}

std::unordered_map<std::string, int> ImageLoaderManager::getImagesFromFile(
                                                std::unordered_map<std::string, int> playerImages){
    playerImages = fileImages_;
    return playerImages;
}

std::unordered_map<std::string, SDL_Rect> ImageLoaderManager::getPlayerClipImages(
                                                std::unordered_map<std::string, SDL_Rect> playerClipImages){
    playerClipImages = playerClipImages_;
    return playerClipImages;
}

std::vector<SDL_Rect> ImageLoaderManager::getClipList(){
    return clipLists_;
} 
    
void ImageLoaderManager::setClipList(std::vector<SDL_Rect> imageClips){
    clipLists_ = imageClips;
} 
