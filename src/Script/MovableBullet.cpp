#include "Script/MovableBullet.h"

void MovableBulletScript::init()
{
	position = &entity->getComponent<TransformComponent>();
}

void MovableBulletScript::update()
{
}

void MovableBulletScript::onCollide(Entity& other)
{
	cout << "Collision" << endl;
}

void MovableBulletScript::handleInput(SDL_Event& event)
{
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

	position->velocity = Vector2D((float)arr[0] + arr[1], (float)arr[2] + arr[3]);
}
