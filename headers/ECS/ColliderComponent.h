#pragma once
#include "SDL.h"
#include "ECS.h"

class ColliderComponent : public Component{
public:
	SDL_Rect collider;
	TransformComponent* transform;

	void init() {
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() {
		collider.x = transform->position.x;
		collider.y = transform->position.y;
		collider.w = transform->width;
		collider.h = transform->height;
	}
};