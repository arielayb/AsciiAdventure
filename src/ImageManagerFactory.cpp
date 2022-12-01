#include <ImageManagerFactory.h>

AbstractImageManager* ImageManagerFactory::createImageManager(){
    return new ImageManager();
}