#pragma once

#include "ECS/Components.h"
#include "Vector2D.h"

class BulletScript : public Behaviour {
	void update() override {
		TransformComponent& position = entity->getComponent<TransformComponent>();
		position.position = position.position + Vector2D(0, 7.5);
	}
};