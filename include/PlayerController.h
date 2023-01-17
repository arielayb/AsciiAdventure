#ifndef _PLAYERCONTROLLER_H
#define _PLAYERCONTROLLER_H

#include <AbstractPlayerController.h>

class PlayerController: public AbstractPlayerController{
    public:

        PlayerController(){};
        ~PlayerController(){};
        void playerInput(SDL_Event events) override;
        bool checkingCollisions(SDL_Rect playerBox, SDL_Rect object) override;
        void collisionManagement(SDL_Rect playerBox) override;
		bool loadWalls(SDL_Rect collision, std::vector<SDL_Rect> wall) override;

        //set the level parameters
		int levelWidth;
		int levelHeight;

        //player's position
		float xPos;
		float yPos;

        //the player's velocity
		float velX;
		float velY;

		//set of walls from the loaded map
		std::vector<SDL_Rect> setOfWalls;

		////set camera 
		//SDL_Rect camera;

		//Maximum axis velocity of the player
		float player_vel = 2.0f;

        //player's collision box
		SDL_Rect collision;

        //the mouse x and y position
		int mouseXPosition, mouseYPosition;

		//determine if the player move up
		bool playerUp;
		bool playerDown;
		bool playerLeft;
		bool playerRight;

		//player facing
		bool playerFacingUp;
		bool playerFacingDown;
		bool playerFacingLeft;
		bool playerFacingRight;

		//player action
		bool eventTouch;
		bool attack;
		bool attackDown;
		bool attackUp;
		bool attackLeft;
		bool attackRight;
};

#endif
