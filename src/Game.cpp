#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Utils.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#include "Scenes/Scene1.h"


using namespace std;

SDL_Renderer* Game::renderer;
int Game::fps = 0;
int Game::width = 0;
int Game::height = 0;
SDL_Event Game::event;



Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

	srand(time(NULL));

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		//cout << "Initialized subsystem" << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		SDL_Surface *temp = IMG_Load("assets/bullet.png");
		SDL_SetWindowIcon(window, temp);
		SDL_FreeSurface(temp);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	SDL_GetWindowSize(window, &Game::width, &Game::height);

	SceneManager::addScene<Scene1>();
}

void Game::handleEvents() {
	SDL_PollEvent(&Game::event);
	switch (Game::event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	};
}

void Game::update() {
	Game::fps++;
	SceneManager::update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	SceneManager::render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Cleaned everything" << endl;
}