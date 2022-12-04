#include "AbstractImageLoaderManager.h"

#ifndef _ABSTRACTIMAGELOADERMANAGERFACTORY_H
#define _ABSTRACTIMAGELOADERMANAGERFACTORY_H

class AbstractImageLoaderManagerFactory {
    public:
        virtual AbstractImageLoaderManager* createImageLoaderManager() = 0;
        virtual AbstractImageLoaderManager* createImageLoaderManagerWithParams(SDL_Texture* image, 
                                                std::string filePath) = 0;

};

#endif