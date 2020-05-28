#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;
class Manager;

constexpr std::size_t kMaxComponents = 32;

using ComponentID = std::size_t;
using ComponentBitSet = std::bitset<kMaxComponents>;
using ComponentArray = std::array<Component*, kMaxComponents>;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

class Component
{
public:
	Entity* entity;

	virtual void init() {};
	virtual void update() {};
	virtual void draw() {};

	virtual ~Component() {};
};

class Entity
{
private:
	bool active = true;
	std::vector < std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	void update();
	void draw();
	void destroy();
	bool isActive();

	template <typename T> bool hasComponent() const;

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* aComponent(new T(std::forward<TArgs>(mArgs)...));

		aComponent->entity = this;
		std::unique_ptr<Component> aComponentUPtr{ aComponent };
		components.emplace_back(std::move(aComponentUPtr));

		componentArray[getComponentTypeID<T>()] = aComponent;
		componentBitSet[getComponentTypeID<T>()] = true;

		aComponent->init();

		return *aComponent;

	}

	template<typename T> T& getComponent() const
	{
		auto aComponentUPtr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(aComponentUPtr);
	}

};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update();
	void draw();
	void refresh();
	Entity& addEntity();
	
};

