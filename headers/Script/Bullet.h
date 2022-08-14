#pragma once
#include "ECS/ECS.h"
#include "ECS/Components.h"
#include <math.h>


class BulletScript : public Behaviour {
private:
	double angle = 0.0;
	TransformComponent* transform = nullptr;
	const char* sprite = "assets/bullet.png";
	double speed = 2.0;
	int fps;

public:
	BulletScript() = default;
	BulletScript(double angle, double speed) {
		this->angle = angle;
		this->speed = speed;
	};

	void init() {
		entity->addComponent<TransformComponent>(250.0f, 250.0f, 258, 258, 0.125);
		entity->addComponent<SpriteComponent>("assets/bullet.png");
		transform = &entity->getComponent<TransformComponent>();
		transform->speed = (float) speed;
	};

	void update() {
		fps++;
		if (fps > 600) entity->getComponent<SpriteComponent>().display = false;
		transform->velocity = Vector2D((float) cos(angle * M_PI / 180.0), (float) sin(angle * M_PI / 180.0)) * speed;
	};
};