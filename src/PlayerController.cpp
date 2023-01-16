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