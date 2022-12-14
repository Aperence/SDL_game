#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }


	static SDL_Renderer* renderer;
	static SDL_Event event;
	static int fps;
	static int width;
	static int height;

private:
	bool isRunning;
	SDL_Window* window;
};

#endif // !GAME

