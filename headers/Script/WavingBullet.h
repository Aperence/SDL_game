#ifndef WAVE_BULLET_H
#define WAVE_BULLET_H


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
	WavingBulletScript(double angle, double speed, float xpos, float ypos) {
		this->angle = angle;
		this->speed = speed;
		center = Vector2D(xpos, ypos);
	};

	void init() {
		entity->addComponent<TransformComponent>(center.x, center.y, 258, 258, 0.08);
		entity->addComponent<SpriteComponent>("assets/bullet.png");
		transform = &entity->getComponent<TransformComponent>();
		transform->speed = (float)speed;
		entity->getComponent<SpriteComponent>().display = false;
	};

	void update() {
		fps++;
		entity->getComponent<SpriteComponent>().display = true;
		Vector2D oscillation = Vector2D( (float) fps*speed , oscillationSize*sin(M_PI * fps / frequency));

		oscillation += center;
		oscillation.rotate(angle, center);

		transform->position = oscillation;

		int x = transform->position.x;
		int y = transform->position.y;
		int w = transform->width;
		int h = transform->height;
		int scale = transform->scale;
		if (x > Game::width + w * scale / 2.0 || x < 0 - w * scale / 2.0 || y > Game::height + h * scale / 2.0 || y < 0 - h * scale / 2.0) {
			entity->destroy();
		}
	};
};

#endif