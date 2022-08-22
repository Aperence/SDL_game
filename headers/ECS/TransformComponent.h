#ifndef TRANSFORM_COMPO_H
#define TRANSFORM_COMPO_H

#include "ECS.h"
#include "Vector2D.h"
#include "Utils.h"
#include <vector>


class TransformComponent : public Component {

public:

	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration = Vector2D();
	//vector<Vector2D*> v = { position, &velocity, &acceleration };
	float speed = 3.0f;


	int width = 32;
	int height = 32;
	float scale = 1;

	TransformComponent();
	TransformComponent(float x, float y);
	TransformComponent(float x, float y, int width, int height, float scale);


	void update();

};
#endif