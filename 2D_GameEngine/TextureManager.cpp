#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* iFileName)
{
	SDL_Surface* aTmpSurface = IMG_Load(iFileName);
	SDL_Texture* aTexture = SDL_CreateTextureFromSurface(Game::renderer, aTmpSurface);
	SDL_FreeSurface(aTmpSurface);

	return aTexture;
}

void TextureManager::Draw(SDL_Texture* iTexture, SDL_Rect iSrcRect, SDL_Rect iDestRect)
{
	//std::cout << "draw something posx  "<< iDestRect.x<<" posy " << iDestRect.y << std::endl;
	SDL_RenderCopy(Game::renderer, iTexture, &iSrcRect, &iDestRect);

}