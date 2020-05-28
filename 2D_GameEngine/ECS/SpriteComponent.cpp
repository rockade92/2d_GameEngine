#include "SpriteComponent.h"
#include "PositionComponent.h"

SpriteComponent::SpriteComponent(const char* iPath)
{
	setTexture(iPath);
}

void SpriteComponent::init()
{
	position = &entity->getComponent<PositionComponent>();

	srcRect.x = srcRect.y;
	srcRect.w = srcRect.h = 32;
	destRect.w = destRect.h = 64;
	
}

void SpriteComponent::setTexture(const char* iPath)
{
	texture = TextureManager::LoadTexture(iPath);
}

void SpriteComponent::update()
{
	destRect.x = position->getx();
	destRect.y = position->gety();

	std::cout << "Update sprite " << destRect.x << ", "<< destRect.y <<std::endl;

}

void SpriteComponent::draw()
{
	TextureManager::Draw(texture, srcRect, destRect);
}
