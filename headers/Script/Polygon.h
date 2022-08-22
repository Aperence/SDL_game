#pragma once

#include "ECS/Components.h"

class Polygon : public Behaviour {

private:
	Vector2D center;
	Vector2D direction;
	float speed;
	double angle;
	double angle_rotation;
	double size;
	Manager* manPtr;
	int nb_bullet = 5;
	int number_sides;

	bool loading = true;
	int index = 0;

public:

	Polygon() = default;
	Polygon(Vector2D c, Vector2D d, double speed, int nb, double rotating_speed, double size, Manager *manager, int nb_bullet = 5);

	void init();

	void update();

	void draw_triangle(double angle);

	void draw_inner(double angle);

	Vector2D getCenter() { return center; }

	bool isLoading() { return loading; }

};