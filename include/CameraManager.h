#ifndef _CAMERAMANAGER_H
#define _CAMERAMANAGER_H

#include <AbstractCameraManager.h>

class CameraManager : public AbstractCameraManager{
    public:
        CameraManager(){};
        ~CameraManager();
        void setZoom(int x, int y) override;
        void initCamera(int x, int y, int w, int h) override;


};

#endif