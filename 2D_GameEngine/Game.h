#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char *iTitle, int ixPos, int iyPos, int iWidth, int iHeight, bool iFullscreen); 
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

	static SDL_Renderer* renderer;

private:
	int counter = 0;
	bool isRunning;
	SDL_Window* window;

};

