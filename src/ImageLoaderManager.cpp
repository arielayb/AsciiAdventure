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

    // std::unordered_map<std::string, int>::const_iterator iter = fileImages_.begin(); 
    // for(std::pair<std::string, int> pair : fileImages_){
    // for(iter; iter != fileImages_.end(); iter++){    

    std::unordered_map<std::string, int>::const_iterator iter = fileImages_.begin(); 
    int jsonFilesize = jsonFiles_.size();
    int k = 0;
    //int size = fileImages_.size();
    for (iter; iter != fileImages_.end(); iter++){
        std::cout << "iter: " << iter->second << std::endl;   

        //std::unordered_map<std::string, int>::const_iterator got = fileImages_.find(iter->first);
        //if ( got == fileImages_.end() ){
        //   std::cout << "json file not found";
        //}else{
            for(int j = 0; j < iter->second; j++){
                std::ifstream jsonFile(jsonFiles_[k]);
                json data = json::parse(jsonFile);
                
                std::string name = data["meta"]["slices"][j]["name"];
                std::cout << "name:" << name << std::endl;

                std::cout << data["meta"]["slices"][j]["keys"][0]["bounds"] << std::endl;

                playerImages_[name].x = data["meta"]["slices"][j]["keys"][0]["bounds"]["x"]; 
                playerImages_[name].y = data["meta"]["slices"][j]["keys"][0]["bounds"]["y"]; 
                playerImages_[name].w = data["meta"]["slices"][j]["keys"][0]["bounds"]["w"]; 
                playerImages_[name].h = data["meta"]["slices"][j]["keys"][0]["bounds"]["h"];

                clipLists_.push_back(playerImages_[name]); 
            }
            k+=1;
       // }
    }

    // for (const auto & entry : std::filesystem::directory_iterator(folderPath)){
    //     std::ifstream jsonFile(entry.path());
    //     json data = json::parse(jsonFile);

            
    // }
    
        // for(int i = 0; i < size; i++){
        //     std::string name =  data["meta"]["slices"][i]["name"];
        //     std::cout << "name:" << name << std::endl;

        //     std::cout << data["meta"]["slices"][i]["keys"][0]["bounds"] << std::endl;

        //     playerImages_[name].x = data["meta"]["slices"][i]["keys"][0]["bounds"]["x"]; 
        //     playerImages_[name].y = data["meta"]["slices"][i]["keys"][0]["bounds"]["y"]; 
        //     playerImages_[name].w = data["meta"]["slices"][i]["keys"][0]["bounds"]["w"]; 
        //     playerImages_[name].h = data["meta"]["slices"][i]["keys"][0]["bounds"]["h"];

        //     clipLists_.push_back(playerImages_[name]); 
            
        // }
    //}
}

std::unordered_map<std::string, SDL_Rect> ImageLoaderManager::getImagesFromFile(
                                                std::unordered_map<std::string, SDL_Rect> playerImages){
    playerImages = playerImages_;
    return playerImages;
}

std::vector<SDL_Rect> ImageLoaderManager::getClipList(){
    return clipLists_;
} 
    
void ImageLoaderManager::setClipList(std::vector<SDL_Rect> imageClips){
    clipLists_ = imageClips;
} 
