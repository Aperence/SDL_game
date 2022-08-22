#include "ECS/TransformComponent.h"

TransformComponent::TransformComponent()
{
	position = Vector2D();
	velocity = Vector2D();
}
TransformComponent::TransformComponent(float x, float y)
{
	position = Vector2D(x, y);
	velocity = Vector2D();
}

TransformComponent::TransformComponent(float x, float y, int width, int height, float scale)
{
	position = Vector2D(x, y);
	this->width = width;
	this->height = height;
	this->scale = scale;
	velocity = Vector2D();
}

void TransformComponent::update()
{
	//Utils::RK4(v, F);
	position += velocity * speed;
}
