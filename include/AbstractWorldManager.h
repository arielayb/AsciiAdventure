#ifndef _ABSTRACTWORLDMANAGER_H
#define _ABSTRACTWORLDMANAGER_H

#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include <tmx.h>

class AbstractWorldInterface {
    public:
        ~AbstractWorldInterface(){};
        //virtual bool loadTiles(std::string tileMapFile, SDL_Renderer* renderer) = 0;
        virtual void* SDL_tex_loader(const char *path) = 0;
        virtual void set_color(int color) = 0;
        virtual void draw_polyline(double **points, double x, double y, int pointsc) = 0;
        virtual void draw_polygon(double **points, double x, double y, int pointsc) = 0;
        virtual void draw_objects(tmx_object_group *objgr) = 0;
        virtual void draw_tile(void *image, unsigned int sx, unsigned int sy, unsigned int sw, unsigned int sh,
            unsigned int dx, unsigned int dy, float opacity, unsigned int flags) = 0;
        virtual void draw_layer(tmx_map *map, tmx_layer *layer) = 0;
        virtual void draw_image_layer(tmx_image *image) = 0;
        virtual void draw_all_layers(tmx_map *map, tmx_layer *layers) = 0;
        virtual void render_map(tmx_map *map) = 0;
        virtual Uint32 timer_func(Uint32 interval, void *param) = 0;
};

#endif