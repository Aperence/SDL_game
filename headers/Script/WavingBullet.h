#ifndef WAVE_BULLET_H
#define WAVE_BULLET_H


#pragma once
#include "ECS/ECS.h"
#include "ECS/Components.h"
#include <math.h>


class WavingBulletScript : public Behaviour {
private:
	TransformComponent* transform = nullptr;
	const char* sprite = "assets/bullet.png";

	// Parameters to change the behaviour of bullets
	double angle = 0.0;
	double speed = 2.0;
	double period = 24.0;
	int oscillationSize = 10;

	Vector2D center = Vector2D(400.0, 200.0);
	int fps = 0;


public:
	WavingBulletScript() = default;
	WavingBulletScript(double angle, double speed, float xpos, float ypos);

	void init();

	void update();
};

#endif