#include "ECS.h"

void Entity::update()
{
	for (auto& aComponent : components)
	{
		aComponent->update();
	}
}

void Entity::draw()
{
	for (auto& aComponent : components)
	{
		aComponent->draw();
	}
	std::cout << "Draw component" << std::endl;

}

void Entity::destroy()
{
	active = false;
}

bool Entity::isActive()
{
	return active;
}

template <typename T> bool Entity::hasComponent() const
{
	return componentBitSet[getComponentTypeID<T>()];
}

void Manager::update()
{
	for (auto& aEntity : entities)
	{
		aEntity->update();
	}
}

void Manager::draw()
{
	for (auto& aEntity : entities)
	{
		aEntity->draw();
	}
}

void Manager::refresh()
{
	entities.erase(std::remove_if(std::begin(entities), std::end(entities),
		[](const std::unique_ptr<Entity>& iEntity)
		{
			return !iEntity->isActive();
		}),
		std::end(entities));
}

Entity& Manager::addEntity()
{
	Entity* aEntity = new Entity();
	std::unique_ptr<Entity> aEntityUPtr{ aEntity };
	entities.emplace_back(std::move(aEntityUPtr));

	return *aEntity;
}