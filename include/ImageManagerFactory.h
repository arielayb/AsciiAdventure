#include "AbstractImageManagerFactory.h"
#include "ImageManager.h"

#ifndef _IMAGEMANAGERFACTORY_H
#define _IMAGEMANAGERFACTORY_H

class ImageManagerFactory : public AbstractImageManagerFactory{
    public:
        virtual AbstractImageManager* createImageManager();

};

#endif