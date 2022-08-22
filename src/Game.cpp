#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Utils.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "ECS/Components.h"
#include "Collision.h"

#include "Script/MovableBullet.h"
#include "Script/BulletSpawner.h"
#include "Script/Polygon.h"


using namespace std;

SDL_Renderer* Game::renderer;
int Game::fps = 0;
int Game::width = 0;
int Game::height = 0;
Manager manager;
auto& bullet = manager.addEntity();
auto& bulletSpawner = manager.addEntity();

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

	float half = 258.0 * 0.125 / 2.0;
	bullet.addComponent<TransformComponent>(width/2 - half ,height/2 - half,258,258,0.125);
	bullet.addComponent<SpriteComponent>("assets/bullet.png");
	bullet.addBehaviour<MovableBulletScript>();
	bullet.addComponent<KeyboardController>();
	bullet.addComponent<ColliderComponent>();

	bulletSpawner.addBehaviour<BulletSpawner>(&manager);
	//bulletSpawner.addBehaviour<Polygon>(Vector2D(200,200), Vector2D(1, 0), 1, 5, 90, 50, &manager, 7);
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
	manager.refresh();
	manager.update();
	manager.checkCollisions();
}

void Game::render() {
	SDL_RenderClear(renderer);
	manager.render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Cleaned everything" << endl;
}