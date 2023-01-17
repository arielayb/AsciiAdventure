#include <WorldManager.h>
#include <ImageManager.h>
#include <fstream>

bool WorldManager::loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::vector<SDL_Rect> tileSet){
    // if (nextLevel)
	// {
	// 	SDL_Rect value = { 0, 0, 0, 0 };
	// 	std::fill(std::begin(setOfWalls), std::end(setOfWalls), value);
		
	// 	_prevLevelfile = _levelfile;
	// 	setLevel(_levelfile);
	
	// }
	// else if (previousLevel)
	// {
	// 	SDL_Rect value = { 0, 0, 0, 0 };
	// 	std::fill(std::begin(setOfWalls), std::end(setOfWalls), value);
		
	// 	_levelfile = _prevLevelfile;
	// 	setLevel(_levelfile);
				
	// }

	//load the map file
	//std::ifstream map(level);
	std::ifstream map(levelfile);

	ImageManager load;

	//set the indexes of the map
	float indexX = 0.0f;
	float indexY = 0.0f;

	if (map.fail())
	{
		printf("the map file is empty or missing!", SDL_GetError());
		return false;
	}

	//this char will be used to draw the map.
	char tile_type;
	char event_type;

	for (int i = 0; i <= total_tiles; i++)
	{
		//read the text file for the first layer
		map >> tile_type;

		switch (tile_type)
		{
		
			case '(':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtTopLeft));
				break;

			case '-':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtHorizontal));
				break;

			case ')':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtTopRight));
				break;

			case ':':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtVertical));
				break;

			case '}':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtBottomRight));
				break;

			case '{':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtBottomLeft));
				break;

			case '4':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtHoriVerLeft));
				break;

			case '6':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtHoriVerRight));
				break;

			case '5':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtFourPaths));
				break;

			case '8':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtVerHoriUp));
				break;

			case '2':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtVerHoriDown));
				break;

			case 'x':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(darkGrass));
				break;

			case 'd':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(dirt));
				break;

			case '~':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(water));
				break;

			case 'g':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grave));
				break;

			case '%':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallBottom));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallBottom));
				break;

			case '=':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallTopEndless));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallTopEndless));
				break;

			case '^':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallTopEnd));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallTopEnd));
				break;

			case '|':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallVertical));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallVertical));
				break;

			case 't':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(tombstone));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(tombstone));
				break;

			case '<':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallCornerTopLeft));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallCornerTopLeft));
				break;

			case '>':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallCornerTopRight));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallCornerTopRight));
				break;

			case ',':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallCornerBottomLeft));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallCornerBottomLeft));
				break;

			case '.':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallCornerBottomRight));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallCornerBottomRight));
				break;

			case '#':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallMiddle));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallMiddle));
				break;

			case 'c':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(cross));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(cross));
				break;

			case '[':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(woodDoor));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(woodDoor));
				break;

			case 'q':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeShortTopLeft));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeShortTopLeft));
				break;

			case 'w':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeShortTopRight));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeShortTopRight));
				break;

			case 'a':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeShortBotLeft));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeShortBotLeft));
				break;

			case 's':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeShortBotRight));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeShortBotRight));
				break;
		}

		indexX += tileWidth_;

		if (indexX >= levelWidth_)
		{
			indexX = 0;

			indexY += tileHeight_;
		}
	}

	map.close();

	//load the hero default sprite
	if (loaded_hero == false)
	{
		player			  = tileSet.at(herodown1);
		collectionStarted = true;
		overrideIndex	  = true;
		loaded_hero		  = true;
	}

	player = playerAnimation(player, tileSet);
	//player = playerSwordAttackAnimation(player, tileSet);

	//collisionManagement(player, setOfWalls, setOfEvents, setOfCoins);
	collisionManagement(player);
	

	/*load.renderTexture(0, 0, NULL, NULL, &camera);
	load.renderTexture(xPos - camera.x, yPos - camera.y, NULL, NULL, NULL);*/
	load.renderTexture(xPos, yPos, image, renderer, &player);
	/*load.renderTexture(0, 0, NULL, NULL, &camera);
	load.renderTexture(xPos - camera.x, yPos - camera.y, NULL, NULL, NULL);*/


	return true;
}