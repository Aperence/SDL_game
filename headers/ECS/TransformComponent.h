#ifndef TRANSFORM_COMPO_H
#define TRANSFORM_COMPO_H

#include "ECS.h"
#include "Vector2D.h"

class TransformComponent : public Component {

public:

	Vector2D position;
	Vector2D velocity;
	float speed = 3.0f;


	int width = 32;
	int height = 32;
	float scale = 1;

	TransformComponent() {
		position = Vector2D();
		velocity = Vector2D();
	};
	TransformComponent(float x, float y) {
		position = Vector2D(x, y);
		velocity = Vector2D();
	}
	TransformComponent(float x, float y, int width, int height, float scale) {
		position = Vector2D(x, y);
		this->width = width;
		this->height = height;
		this->scale = scale;
		velocity = Vector2D();
	}

	void update() {
		velocity.normalize();
		position += velocity*speed;
	}

};
#endif