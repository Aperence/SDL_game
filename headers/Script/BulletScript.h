#ifndef BULLET_H
#define BULLET_h

#include "ECS/ECS.h"
#include "ECS/Components.h"
#include <math.h>


class BulletScript : public Behaviour {
private:

	TransformComponent* transform = nullptr;
	const char* sprite = "assets/bullet.png";
	double angle = 0.0;
	double speed = 2.0;
	int fps;
	float x, y;

public:
	BulletScript() = default;
	BulletScript(double angle, double speed, float xpos, float ypos);

	void init();

	void update();
};
#endif