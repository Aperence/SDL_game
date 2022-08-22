#pragma once

#include "ECS/Components.h"
#include "Polygon.h"

class PolygonBullet : public Behaviour {
private:
	static int count;
	Polygon* parent;
	Vector2D direction;
	TransformComponent* transform;
	float speed;
	double angle_rotation;
	Vector2D pos;

public:

	PolygonBullet() = default;
	PolygonBullet(Polygon* p, Vector2D d, double speed, double rotating_speed, Vector2D pos);

	void init();

	void update();
};