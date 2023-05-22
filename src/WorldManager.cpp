#include <WorldManager.h>
#include <ImageManager.h>
#include <SDL2/SDL_image.h>
#include <tmx.h>
#include <fstream>

WorldManager::WorldManager(SDL_Renderer* ren)
: ren_(ren)
{
    // const char * test = "/home/aaybar/Documents/test/testMap.tmx";
    // // timer_id = SDL_AddTimer(30, worldMgr->timer_func(), NULL);
    // /* Set the callback globs in the main function */
	// tmx_img_load_func = SDL_tex_loader;
    // tmx_img_free_func = (void (*)(void*))SDL_DestroyTexture;
    
    // tmx_map *map = tmx_load(test.c_str());
	// if (!map) {
	// 	tmx_perror("Cannot load map");
	// 	return 1;
	// }
}

WorldManager::WorldManager(int width, int height, SDL_Renderer* ren):
ren_(ren)    
{}

// bool WorldManager::loadTiles(std::string tileMapFile, SDL_Renderer* renderer){
//     SDL_TimerID timer_id;
//     timer_id = SDL_AddTimer(30, timer_func, NULL);

// 	/* Set the callback globs in the main function */
// 	tmx_img_load_func = SDL_tex_loader;
// 	tmx_img_free_func = (void (*)(void*))SDL_DestroyTexture;

// 	tmx_map *map = tmx_load(argv[1]);
// 	if (!map) {
// 		tmx_perror("Cannot load map");
// 		return 1;
// 	}
	
	
// }

void* WorldManager::SDL_tex_loader(const char *path) {
	return IMG_LoadTexture(ren_, path);
}

void WorldManager::set_color(int color) {
	tmx_col_bytes col = tmx_col_to_bytes(color);
	SDL_SetRenderDrawColor(ren_, col.r, col.g, col.b, col.a);
}

void WorldManager::draw_polyline(double **points, double x, double y, int pointsc) {
	int i;
	for (i=1; i<pointsc; i++) {
		SDL_RenderDrawLine(ren_, x+points[i-1][0], y+points[i-1][1], x+points[i][0], y+points[i][1]);
	}
}

void WorldManager::draw_polygon(double **points, double x, double y, int pointsc) {
	draw_polyline(points, x, y, pointsc);
	if (pointsc > 2) {
		SDL_RenderDrawLine(ren_, x+points[0][0], y+points[0][1], x+points[pointsc-1][0], y+points[pointsc-1][1]);
	}
}

void WorldManager::draw_objects(tmx_object_group *objgr) {
	SDL_Rect rect;
	set_color(objgr->color);
	tmx_object *head = objgr->head;
	while (head) {
		if (head->visible) {
			if (head->obj_type == OT_SQUARE) {
				rect.x = head->x;  
				rect.y = head->y;
				rect.w = head->width;  
				rect.h = head->height;
				SDL_RenderDrawRect(ren_, &rect);
			}
			else if (head->obj_type  == OT_POLYGON) {
				draw_polygon(head->content.shape->points, head->x, head->y, head->content.shape->points_len);
			}
			else if (head->obj_type == OT_POLYLINE) {
				draw_polyline(head->content.shape->points, head->x, head->y, head->content.shape->points_len);
			}
			else if (head->obj_type == OT_ELLIPSE) {
				/* FIXME: no function in SDL2 */
			}
		}
		head = head->next;
	}
}

void WorldManager::draw_tile(void *image, unsigned int sx, unsigned int sy, unsigned int sw, unsigned int sh,
               unsigned int dx, unsigned int dy, float opacity, unsigned int flags) {
	SDL_Rect src_rect, dest_rect;
	src_rect.x = sx;
	src_rect.y = sy;
	src_rect.w = dest_rect.w = sw;
	src_rect.h = dest_rect.h = sh;
	dest_rect.x = dx;
	dest_rect.y = dy;
	SDL_RenderCopy(ren_, (SDL_Texture*)image, &src_rect, &dest_rect);
}

void WorldManager::draw_layer(tmx_map *map, tmx_layer *layer) {
	unsigned long i, j;
	unsigned int gid, x, y, w, h, flags;
	float op;
	tmx_tileset *ts;
	tmx_image *im;
	void* image;
	op = layer->opacity;
	for (i=0; i<map->height; i++) {
		for (j=0; j<map->width; j++) {
			gid = (layer->content.gids[(i*map->width)+j]) & TMX_FLIP_BITS_REMOVAL;
			if (map->tiles[gid] != NULL) {
				ts = map->tiles[gid]->tileset;
				im = map->tiles[gid]->image;
				x  = map->tiles[gid]->ul_x;
				y  = map->tiles[gid]->ul_y;
				w  = ts->tile_width;
				h  = ts->tile_height;
				if (im) {
					image = im->resource_image;
				}
				else {
					image = ts->image->resource_image;
				}
				flags = (layer->content.gids[(i*map->width)+j]) & ~TMX_FLIP_BITS_REMOVAL;
				draw_tile(image, x, y, w, h, j*ts->tile_width, i*ts->tile_height, op, flags);
			}
		}
	}
}

void WorldManager::draw_image_layer(tmx_image *image) {
	SDL_Rect dim;
	dim.x = dim.y = 0;

	SDL_Texture *texture = (SDL_Texture*)image->resource_image; // Texture loaded by libTMX
	SDL_QueryTexture(texture, NULL, NULL, &(dim.w), &(dim.h));
	SDL_RenderCopy(ren_, texture, NULL, &dim);
}

void WorldManager::draw_all_layers(tmx_map *map, tmx_layer *layers) {
	while (layers) {
		if (layers->visible) {

			if (layers->type == L_GROUP) {
				draw_all_layers(map, layers->content.group_head);
			}
			else if (layers->type == L_OBJGR) {
				draw_objects(layers->content.objgr);
			}
			else if (layers->type == L_IMAGE) {
				draw_image_layer(layers->content.image);
			}
			else if (layers->type == L_LAYER) {
				draw_layer(map, layers);
			}
		}
		layers = layers->next;
	}
}

void WorldManager::render_map(tmx_map *map) {
	set_color(map->backgroundcolor);
	SDL_RenderClear(ren_);
	draw_all_layers(map, map->ly_head);
}

Uint32 WorldManager::timer_func(Uint32 interval, void *param) {
	SDL_Event event;
	SDL_UserEvent userevent;

	userevent.type = SDL_USEREVENT;
	userevent.code = 0;
	userevent.data1 = NULL;
	userevent.data2 = NULL;

	event.type = SDL_USEREVENT;
	event.user = userevent;

	SDL_PushEvent(&event);
	return(interval);
}

std::string WorldManager::getImageFile(std::string filePath){

    files = imgLoadMgr->getImagesFromFile(files);
    imageFileIter = files.find(filePath);

    //SDL_Rect clip;
    if ( imageFileIter == files.end() ){
       std::cout << "not found" << std::endl;
    }else{
        file_ = imageFileIter->first;
        std::cout << "filename: " << file_ << std::endl; 
    }

    return file_;
}