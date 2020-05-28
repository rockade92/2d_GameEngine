#include "Map.h"
#include "TextureManager.h"

std::vector<std::vector<int>> initializeMap()
{
	std::cout << "Initialize map" << std::endl;
	std::vector<std::vector<int>> aMap;

	aMap.resize(20);

	for (auto& aVector : aMap)
	{
		
		aVector.resize(25, 0);
	}
	
	return aMap;
}

Map::Map()
{
	dirt = TextureManager::LoadTexture("Assets/dirt.png");
	grass = TextureManager::LoadTexture("Assets/grass.png");
	water = TextureManager::LoadTexture("Assets/water.png");

	LoadMap(initializeMap());

	src.x = src.y = 0;
	src.h = src.w = 32;

	dest.x = dest.y = 0;
	dest.h = dest.w = 32;

}

void Map::LoadMap(std::vector<std::vector<int>> iMap)
{
	map = iMap;
}

void Map::DrawMap()
{
	int type = 0;

	for (int row = 0; row <20; row++)
	{
		for (int col = 0; col < 25; col++)
		{
			type = map[row][col];

			dest.x = col*32;
			dest.y = row*32;

			switch (type)
			{
			case 0: 
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			}
			

		}
		
	}

}
