#ifndef MOVABLE_BULLET_H
#define MOVABLE_BULLET_H

#include "ECS/Components.h"
#include "Vector2D.h"
#include <math.h>

class MovableBulletScript : public Behaviour {
private:
	TransformComponent* position = nullptr;
	int arr[4] = { 0,0,0,0 };

public:

	void init() override;

	void update() override;

	void onCollide(Entity& other);

	
	void handleInput(SDL_Event& event) override;
};

#endif