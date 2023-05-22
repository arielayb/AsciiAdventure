#ifndef _WORLDMANAGER_H
#define _WORLDMANAGER_H

#include "AbstractWorldManager.h"
#include "AbstractImageManagerFactory.h"
#include "AbstractImageLoaderManagerFactory.h"
#include "ImageLoaderManagerFactory.h"
#include "ImageManagerFactory.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <tmx.h>

class WorldManager : public AbstractWorldInterface {
    public:
        WorldManager(){};
        WorldManager(int width, int height, SDL_Renderer* ren);
        WorldManager(SDL_Renderer* ren);
        ~WorldManager(){};
        //bool loadTiles(std::string tileMapFile, SDL_Renderer* renderer) override;
        
        //using the tmx tileset library
        void* SDL_tex_loader(const char *path) override;
        void set_color(int color) override;
        void draw_polyline(double **points, double x, double y, int pointsc);
        void draw_polygon(double **points, double x, double y, int pointsc);
        void draw_objects(tmx_object_group *objgr);
        void draw_tile(void *image, unsigned int sx, unsigned int sy, unsigned int sw, unsigned int sh,
            unsigned int dx, unsigned int dy, float opacity, unsigned int flags);
        void draw_layer(tmx_map *map, tmx_layer *layer);
        void draw_image_layer(tmx_image *image);
        void draw_all_layers(tmx_map *map, tmx_layer *layers);
        void render_map(tmx_map *map);
        Uint32 timer_func(Uint32 interval, void *param);

        std::string getImageFile(std::string filePath);

        //  set the level, items, and events
	    std::string levelfile;
        std::unordered_map<std::string, int> files; // container for image files.
        std::unordered_map<std::string, int>::const_iterator imageFileIter; //iterator for image file container.

        SDL_Texture* image = nullptr;

        ImageManagerFactory* imgFac = nullptr;
    	AbstractImageManager* imgMgr = nullptr;
		ImageLoaderManagerFactory* imgLoadFac = nullptr;
    	AbstractImageLoaderManager* imgLoadMgr = nullptr;
    private:
        std::string file_;
        SDL_Renderer* ren_;
};

#endif