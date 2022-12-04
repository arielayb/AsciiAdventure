#include <ImageManagerFactory.h>

AbstractImageManager* ImageManagerFactory::createImageManager(){
    return new ImageManager();
}

AbstractImageManager* ImageManagerFactory::createImageManagerWithParams(SDL_Texture* image, 
                                                             SDL_Renderer* render)
{
    return new ImageManager(image, render);
}
