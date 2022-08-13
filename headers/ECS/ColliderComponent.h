#pragma once
#include "SDL.h"
#include "ECS.h"
#include <string>

class ColliderComponent : public Component{
public:
	SDL_Rect collider;
	string tag;
	TransformComponent* transform = nullptr;

	ColliderComponent() = default;
	ColliderComponent(string desc) {
		tag = desc;
	}

	void init() {
		if (!entity->hasComponent<TransformComponent>()) {
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() {
		collider.x = transform->position.x;
		collider.y = transform->position.y;
		collider.w = static_cast<int>(transform->width*transform->scale);
		collider.h = static_cast<int>(transform->height * transform->scale);
	}
};