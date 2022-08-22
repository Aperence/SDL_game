#ifndef COLLIDER_H
#define COLLIDER_H

#include "SDL.h"
#include "ECS.h"
#include "Components.h"
#include <string>

class ColliderComponent : public Component{
public:
	SDL_Rect collider;
	string tag;
	TransformComponent* transform = nullptr;

	ColliderComponent() = default;
	ColliderComponent(string desc);

	void init();

	void update();
};
#endif