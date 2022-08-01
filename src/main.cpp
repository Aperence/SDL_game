#include <SDL.h>
#include "Game.h"

int main(int argc, char** argv) {

	const int FPS = 60;
	const int FrameDelay = 1000 / 60;

	Uint32 FrameStart;
	int FrameTime;

	Game* game = new Game();

	game->init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 450, false);

	while (game->running()) {

		FrameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		FrameTime = SDL_GetTicks() - FrameStart;

		if (FrameDelay > FrameTime) {
			SDL_Delay(FrameDelay - FrameTime);
		}
	}

	game->clean();

	delete game;

	return 0;

}