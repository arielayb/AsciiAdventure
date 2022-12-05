#include <string>
#include "AbstractImageLoaderManagerFactory.h"
#include "ImageLoaderManager.h"

#ifndef _IMAGELOADERMANAGERFACTORY_H
#define _IMAGELOADERMANAGERFACTORY_H

class ImageLoaderManagerFactory : public AbstractImageLoaderManagerFactory{
    public:
        virtual AbstractImageLoaderManager* createImageLoaderManager();
        virtual AbstractImageLoaderManager* createImageLoaderManagerWithParams(SDL_Texture* image, 
                                                                        std::string folderPath);

};

#endif