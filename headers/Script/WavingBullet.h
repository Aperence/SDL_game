#pragma once


#pragma once
#include "ECS/ECS.h"
#include "ECS/Components.h"
#include <math.h>


class WavingBulletScript : public Behaviour {
private:
	double angle = 0.0;
	TransformComponent* transform = nullptr;
	const char* sprite = "assets/bullet.png";
	double speed = 2.0;
	Vector2D center = Vector2D(400.0, 200.0);
	int fps = 0;
	double frequency = 24.0;
	int oscillationSize = 10;

public:
	WavingBulletScript() = default;
	WavingBulletScript(double angle, double speed) {
		this->angle = angle;
		this->speed = speed;
	};

	void init() {
		entity->addComponent<TransformComponent>(center.x - 129.0*0.125, center.y - 129.0 * 0.125, 258, 258, 0.125);
		entity->addComponent<SpriteComponent>("assets/bullet.png");
		transform = &entity->getComponent<TransformComponent>();
		transform->speed = (float)speed;
		entity->getComponent<SpriteComponent>().display = false;
	};

	void update() {
		fps++;
		//if (fps < 600) return;
		entity->getComponent<SpriteComponent>().display = true;
		Vector2D oscillation = Vector2D( (float) fps*2 , oscillationSize*sin(M_PI * fps / frequency));

		oscillation += center;
		oscillation.rotate(angle, center);

		transform->position = oscillation;
	};
};