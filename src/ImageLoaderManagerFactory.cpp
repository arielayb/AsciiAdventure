#include <ImageLoaderManagerFactory.h>

AbstractImageLoaderManager* ImageLoaderManagerFactory::createImageLoaderManager()
{
    return new ImageLoaderManager();
}

AbstractImageLoaderManager* ImageLoaderManagerFactory::createImageLoaderManagerWithParams(SDL_Texture* image, 
                                                            std::string filePath)
{
    return new ImageLoaderManager(image, filePath);
}