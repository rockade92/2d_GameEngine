#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* iTextureSheet,  int x, int y);

	void Update();
	void Render();

private:

	int xpos, ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

