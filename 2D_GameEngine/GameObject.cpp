#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* iTextureSheet, int x, int y)  : objTexture(TextureManager::LoadTexture(iTextureSheet)), xpos(x), ypos(y) {}

void GameObject::Update()
{
	xpos ++;
	ypos ++;

	srcRect.h = 32;
	srcRect.w = 32;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;

}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}