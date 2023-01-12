//load media stuff
#include "ImageManager.h"

ImageManager::ImageManager()
{
	//I do nothing
}

ImageManager::ImageManager(SDL_Texture* image, SDL_Renderer* render)
{
	image_ = image;
	render_ = render;
}

ImageManager::~ImageManager()
{
	if(image_ != nullptr){
		SDL_DestroyTexture(image_);
	}

	if(render_ != nullptr){
		SDL_DestroyRenderer(render_);
	}
}

//load the texture
SDL_Texture* ImageManager::loadTexture(const std::string file, SDL_Texture *image, SDL_Renderer* render)
{
	
	image_  = image;
	render_ = render;

	//load the image file and set the parameters
	SDL_Surface* loaded_surface = IMG_Load(file.c_str());

	//the width and height of an image 
	int image_width;
	int image_height;

	if(loaded_surface == NULL)
	{
		printf("the surface was unable to load %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	else
	{
		//get the image dimensions
		image_height = loaded_surface->h;
		image_width = loaded_surface->w;
		
		//set the the image alpha color
		SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));

		//create the texture from the surface
		image = SDL_CreateTextureFromSurface(render, loaded_surface);

		if (image == NULL)
		{
			printf("the texture was unable to load %s\n", SDL_GetError());
		}

		//free the image surface
		SDL_FreeSurface(loaded_surface);

	}

	return image;
}

SDL_Texture* ImageManager::loadFont(std::string text, TTF_Font* fontType, SDL_Color fontColor, SDL_Renderer* render)
{

    SDL_Texture* textureFont = NULL;

	SDL_Surface* loaded_fontSurface = TTF_RenderText_Solid(fontType, text.c_str(), fontColor);
	
	if (loaded_fontSurface == NULL)
	{
		printf("unable to load font! %s\n", TTF_GetError());
	}
	else
	{
		//create the texture from the surface
		textureFont = SDL_CreateTextureFromSurface(render, loaded_fontSurface);

		if (textureFont == NULL)
		{
			printf("unable to load texture %s\n", SDL_GetError());
		}

		//free the text surface
		SDL_FreeSurface(loaded_fontSurface);
	}

	return textureFont;
}

//load the sprites on the screen
bool ImageManager::renderTexture(float x, float y, SDL_Texture* image, SDL_Renderer* render, SDL_Rect clip)
{
	SDL_Rect renderQuad;

	renderQuad.x = x;
	renderQuad.y = y;

	Uint32 pixelFormat;
	
	if (image != NULL)
	{
		renderQuad.h = clip.h;
		renderQuad.w = clip.w;
	}
	else
	{
		SDL_QueryTexture(image, &pixelFormat, NULL, &renderQuad.w, &renderQuad.h);
	}

	SDL_RenderCopy(render, image, &clip, &renderQuad);

	return true;
}

//load the text on the screen
bool ImageManager::renderText(float x, float y, SDL_Texture* image, SDL_Renderer* render, SDL_Rect* clip)
{
	SDL_Rect renderQuad;

	renderQuad.x = x;
	renderQuad.y = y;

	Uint32 pixelFormat;
	
	if (clip != NULL)
	{
		renderQuad.h = clip->h;
		renderQuad.w = clip->w;
	}
	else
	{
		SDL_QueryTexture(image, &pixelFormat, NULL, &renderQuad.w, &renderQuad.h);
	}

	SDL_RenderCopy(render, image, clip, &renderQuad);

	return true;
}