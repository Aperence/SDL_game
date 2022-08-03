#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Bullet.h"

using namespace std;

Bullet* bullet;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		cout << "Initialized subsystem" << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	bullet = new Bullet("assets/bullet.png", renderer, 0, 0);
	bullet->initSrcRect(0, 0, 258, 258);
	bullet->initDestRect(0, 0, 128, 128);
	
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	};
}

void Game::update() {
	bullet->update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	bullet->render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete bullet;
	SDL_Quit();
	cout << "Cleaned everything" << endl;
}