#include <PlayerController.h>
#include <iostream>

//  the collision management and set of wall detection for the player.
void PlayerController::collisionManagement(SDL_Rect playerBox)
{
	//float32 timeStep = 1.0f / 60.0f;
	
	//  set the player's collision box
	collision.h = playerBox.h;
	collision.w = playerBox.w;

	/********Trying to set the box2d library*******/
	
	//_playerShape.SetAsBox((float)collision.w, (float)collision.h);
	//_body->CreateFixture(&_playerShape, 1);//shape, density

	//_body->SetUserData(this);

	/*********************************************/

	//  set the exact position of the box from box2d library
	/*float32 angle	= _body->GetAngle();
	b2Vec2 position = _body->GetPosition();*/

	//  move the player right on the x, y plane
	xPos += velX;
	collision.x = xPos;

	//position.x = (float)collision.x;

	//if the dot goes to far off the screen.
	if ((xPos < 0) || (collision.x + collision.w >= levelWidth) || loadWalls(collision, setOfWalls))
	{
		//move the player from the left side of the x, y plane.
		xPos -= velX;
		collision.x = xPos;
	}

	//  move the player up on the x, y plane
	yPos += velY;
	collision.y = yPos;

	//position.y = (float)collision.y;

	//  if the dot goes to far off the screen.
	if ((yPos < 0) || (collision.y + collision.h >= levelHeight) || loadWalls(collision, setOfWalls))
	{
		//move the player down on the x, y plane
		yPos -= velY;
		collision.y = yPos;
	}

	//printf("player position: x: %d, y: %d\n", collision.x, collision.y);

	//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

	//  set of events that have interaction with the player
	// if (eventsEnabled == true)
	// {
	// 	loadEvents(collision, setOfEvents);
	// 	loadCoins(collision, setOfCoins);
	// 	loadTransition(collision, setOfTransition);
	// }

}

//the input of the player's control
void PlayerController::playerInput(SDL_Event events)
{
	//movement part
	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_UP:
				playerUp = true;
				if (playerUp == true)
				{
					velY -= player_vel;
				}
				break;
			case SDLK_DOWN:
				playerDown = true;
				if (playerDown == true)
				{
					velY += player_vel;
				}
				break;
			case SDLK_LEFT:
				playerLeft = true;
				if (playerLeft == true)
				{
					velX -= player_vel;
				}
				break;
			case SDLK_RIGHT:
				playerRight = true;
				if (playerRight == true)
				{
					velX += player_vel;
				}
				break;
		}
	}
	else if (events.type == SDL_KEYUP && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_UP:
				playerUp = false;
				if (playerUp == false)
				{
					velY += player_vel;
				}
				break;
			case SDLK_DOWN:
				playerDown = false;
				if (playerDown == false)
				{
					velY -= player_vel;
				}
				break;
			case SDLK_LEFT:
				playerLeft = false;
				if (playerLeft == false)
				{
					velX += player_vel;
				}
				break;
			case SDLK_RIGHT:
				playerRight = false;
				if (playerRight == false)
				{
					velX -= player_vel;
				}
				break;
		}
	}

	//action inputs
	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_z:
				eventTouch = true;
			break;
			case SDLK_x:
				attack = true;
				std::cout << "the attack key was pressed" << std::endl;
				if (playerFacingDown == true && attackDown ==false)
				{
					attackDown = true;
				}
			break;
		}
	}
	else if (events.type == SDL_KEYUP && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_z:
				eventTouch = false;
			break;
			case SDLK_x:
				attack = false;
			break;
		}
	}

	//If mouse event happened 
	if (events.type == SDL_MOUSEMOTION || events.type == SDL_MOUSEBUTTONDOWN || events.type == SDL_MOUSEBUTTONUP)
	{ 
		//Get mouse position 
		SDL_GetMouseState(&mouseXPosition, &mouseYPosition);
		std::cout << "x: " << mouseXPosition << " y: " << mouseYPosition << std::endl;
	}

}

//the collision detection fucntion
bool PlayerController::checkingCollisions(SDL_Rect playerBox, SDL_Rect object)
{
	//calculate the rectangle side A
	int checkLeftA	 = playerBox.x;
	int checkRightA  = playerBox.x + playerBox.w;
	int checkTopA	 = playerBox.y;
	int checkBottomA = playerBox.y + playerBox.h;

	//calculate the rectangle side B
	int checkLeftB   = object.x;
	int checkRightB  = object.x + object.w;
	int checkTopB	 = object.y;
	int checkBottomB = object.y + object.h / 2;

	if (checkLeftA >= checkRightB)
	{
		return false;
	}

	if (checkRightA <= checkLeftB)
	{
		return false;
	}

	if (checkTopA >= checkBottomB)
	{
		return false;
	}

	if (checkBottomA <= checkTopB)
	{
		return false;
	}

	return true;
}