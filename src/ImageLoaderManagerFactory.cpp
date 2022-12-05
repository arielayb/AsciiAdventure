#include <ImageLoaderManagerFactory.h>

AbstractImageLoaderManager* ImageLoaderManagerFactory::createImageLoaderManager()
{
    return new ImageLoaderManager();
}

AbstractImageLoaderManager* ImageLoaderManagerFactory::createImageLoaderManagerWithParams(SDL_Texture* image, 
                                                            std::string folderPath)
{
    return new ImageLoaderManager(image, folderPath);
}