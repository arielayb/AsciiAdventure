#include "AbstractImageManager.h" 

#ifndef _ABSTRACTIMAGEMANAGERFACTORY_H
#define _ABSTRACTIMAGEMANAGERFACTORY_H

class AbstractImageManagerFactory {
    public:
        virtual AbstractImageManager* CreateImageManager() = 0;

};

#endif