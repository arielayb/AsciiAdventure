#ifndef _ABSTRACTCAMERAMANAGER_H
#define _ABSTRACTCAMERAMANAGER_H

class AbstractCameraManager{
    public:
        ~AbstractCameraManager(){};

        virtual void setZoom(int x, int y) = 0;
        virtual void initCamera(int x, int y, int w, int h) = 0;

};

#endif