#include "Game.h"

using namespace std;

SDL_Texture* bulletTex;
SDL_Rect bulletRect;
bool renderBlt = true;

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
	SDL_Surface* tmpSurf = IMG_Load("assets/bullet.png");
	bulletTex = SDL_CreateTextureFromSurface(renderer, tmpSurf);
	cout << "Loaded Texture" << endl;
	bulletRect = { 0,0,32,32 };
	SDL_FreeSurface(tmpSurf);
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
	bulletRect.x++;
	if (bulletRect.x >= 800 + 32) {
		renderBlt = false;
	}
}

void Game::render() {
	SDL_RenderClear(renderer);
	if (renderBlt) {
		SDL_RenderCopy(renderer, bulletTex, NULL, &bulletRect);
	}
	else {
		cout << "Stop rendering" << endl;
	}
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(bulletTex);
	SDL_Quit();
	cout << "Cleaned everything" << endl;
}