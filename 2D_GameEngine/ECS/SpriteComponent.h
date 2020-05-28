#pragma once

#include "SDL.h"
#include "../TextureManager.h"
#include "ECS.h"

class PositionComponent;

class SpriteComponent : public Component
{
private:
	PositionComponent *position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* iPath);

	void setTexture(const char* iPath);
	
	void init() override;
	void update() override;
	void draw() override;

};

