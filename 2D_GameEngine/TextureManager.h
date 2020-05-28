#pragma once

#include "Game.h"


class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* iFileName);
	static void Draw(SDL_Texture* iTexture, SDL_Rect iSrcRect, SDL_Rect iDestRect);

};

