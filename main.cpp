#include <SDL.h>
#include "Game.h"

int main(int argc, char** argv) {

	Game* game = new Game();

	game->init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 450, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	delete game;

	return 0;

}