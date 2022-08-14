#ifndef MOVABLE_BULLET_H
#define MOVABLE_BULLET_H

#include "ECS/Components.h"
#include "Vector2D.h"
#include <math.h>

class MovableBulletScript : public Behaviour {

public:

	TransformComponent *position = nullptr;
	int arr[4] = {0,0,0,0};


	void init() override {
		position = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		//position.position = position.position + Vector2D(0, 7.5);
	}

	void onCollide(Entity& other) {
		cout << "Collision" << endl;
	}

	
	void handleInput(SDL_Event& event) override {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_q:
				arr[0] = -1;
				break;
			case SDLK_d:
				arr[1] = 1;
				break;
			case SDLK_z:
				arr[2] = -1;
				break;
			case SDLK_s:
				arr[3] = 1;
				break;
			default:
				break;
			}


		}
		if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_q:
				arr[0] = 0;
				break;
			case SDLK_d:
				arr[1] = 0;
				break;
			case SDLK_z:
				arr[2] = 0;
				break;
			case SDLK_s:
				arr[3] = 0;
				break;
			default:
				break;
			}
		}

		position->velocity = Vector2D((float) arr[0] + arr[1], (float) arr[2] + arr[3]);
	}
};

#endif