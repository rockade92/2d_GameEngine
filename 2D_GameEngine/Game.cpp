#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char *iTitle, int ixPos, int iyPos, int iWidth, int iHeight, bool iFullscreen)
{
	int aFlags = 0;
	if ( iFullscreen )
	{
		aFlags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0 )
	{
		std::cout << "Subsystems Initialized!" << std::endl;
		window = SDL_CreateWindow(iTitle, ixPos, iyPos, iWidth, iHeight, aFlags);

		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;

	}
	else
	{
		isRunning = false;
	}

	map = new Map();

	player.addComponent<PositionComponent>(0,0);
	player.addComponent<SpriteComponent>("Assets/player_anim.png");

}

void Game::handleEvents()
{
	SDL_Event aEvent;
	SDL_PollEvent(&aEvent);

	switch (aEvent.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}

}

void Game::update()
{
	manager.refresh();
	manager.update();

}

void Game::render()
{
	SDL_RenderClear(renderer);

	map->DrawMap();
	manager.draw();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}