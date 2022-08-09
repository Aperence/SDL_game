#ifndef TRANSFORM_COMPO_H
#define TRANSFORM_COMPO_H

#include "ECS.h"
#include "Vector2D.h"

class TransformComponent : public Component {

public:

	Vector2D position;
	TransformComponent() {
		position = Vector2D();
	};
	TransformComponent(float x, float y) {
		position = Vector2D(x, y);
	}

};
#endif