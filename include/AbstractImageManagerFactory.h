#include "AbstractImageManager.h" 

#ifndef _ABSTRACTIMAGEMANAGERFACTORY_H
#define _ABSTRACTIMAGEMANAGERFACTORY_H

class AbstractImageManagerFactory {
    public:
        virtual AbstractImageManager* createImageManager() = 0;

};

#endif