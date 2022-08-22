#include "ECS/ColliderComponent.h"

ColliderComponent::ColliderComponent(string desc)
{
	tag = desc;
}

void ColliderComponent::init()
{
	if (!entity->hasComponent<TransformComponent>()) {
		entity->addComponent<TransformComponent>();
	}
	transform = &entity->getComponent<TransformComponent>();
}

void ColliderComponent::update()
{
	collider.x = (int)transform->position.x;
	collider.y = (int)transform->position.y;
	collider.w = static_cast<int>(transform->width * transform->scale);
	collider.h = static_cast<int>(transform->height * transform->scale);
}
