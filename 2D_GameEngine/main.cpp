#include "Game.h"
#include <memory>



int main(int argc, char*  argv[])
{

	const int kFPS = 60;
	const int kFrameDelay = 1000 / kFPS;

	Uint32 aFrameStart;
	int aFrameTime;

	Game *aGame = new Game();
	
	aGame->init("2D_Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (aGame->running())
	{
		aFrameStart = SDL_GetTicks();

		aGame->handleEvents();
		aGame->update();
		aGame->render();

		aFrameTime = SDL_GetTicks() - aFrameStart;

		if (kFrameDelay > aFrameTime)
		{
			SDL_Delay(kFrameDelay - aFrameTime);
		}

	}

	aGame->clean();

	return 0;


}