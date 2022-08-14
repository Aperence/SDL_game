#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Utils.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "ECS/Components.h"
#include "Script/MovableBullet.h"
#include "Script/Bullet.h"
#include "Script/WavingBullet.h"
#include "Collision.h"


using namespace std;



SDL_Renderer* Game::renderer;
Manager manager;
auto& bullet = manager.addEntity();

#define N_BULLET 18
Entity *bullets[N_BULLET];
Entity *wavingBullets[N_BULLET];

SDL_Event Game::event;



Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

	srand(time(NULL));

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		cout << "Initialized subsystem" << endl;

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
	/*
	for (size_t i = 0; i < 440; i+=25)
	{
		Bullet *bullet = new Bullet("assets/bullet.png", 0, i);
		bullet->initSrcRect(0, 0, 258, 258);
		bullet->initDestRect(0, i, 20, 20);
		bullet->setPhysic(50, 0, rand() % 10, 0);
	}*/

	bullet.addComponent<TransformComponent>(0,0,258,258,0.25);
	bullet.addComponent<SpriteComponent>("assets/bullet.png");
	bullet.getComponent<SpriteComponent>().setSrc(258, 258);
	bullet.addBehaviour<MovableBulletScript>();
	bullet.addComponent<KeyboardController>();
	bullet.addComponent<ColliderComponent>();

	for (size_t i = 0; i < N_BULLET; i++)
	{
		/*
		Entity *e = &manager.addEntity();
		bullets[i] = e;
		e->addBehaviour<BulletScript>(i * (360.0/ N_BULLET), 1.0);*/

		Entity* w = &manager.addEntity();
		wavingBullets[i] = w;
		w->addBehaviour<WavingBulletScript>(i * (360.0 / N_BULLET), 1.0);
	}
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
	manager.refresh();
	manager.update();
	manager.checkCollisions();
	/*
	if (Collision::AABB(bullet.getComponent<ColliderComponent>().collider, bullet2.getComponent<ColliderComponent>().collider)) {
		cout << "Collision" << endl;
	}*/
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