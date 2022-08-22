#include "Script/Polygon_Bullet.h"

int PolygonBullet::count = 0;

PolygonBullet::PolygonBullet(Polygon* p, Vector2D d, double speed, double rotating_speed, Vector2D pos)
{	
	
	parent = p;
	direction = d;
	this->speed = speed;
	angle_rotation = rotating_speed;
	transform = nullptr;
	this->pos = pos;
}

void PolygonBullet::init()
{
	transform = &entity->addComponent<TransformComponent>(pos.x, pos.y, 258, 258, 0.05);
	entity->addComponent<ColliderComponent>();
	entity->addComponent<SpriteComponent>("assets/bullet.png");
}

void PolygonBullet::update()
{
	if (parent->isLoading()) return;
	transform->position += direction * speed;
	transform->position.rotate(angle_rotation, parent->getCenter());
	if (!entity->hasComponent<TransformComponent>()) return;
	if (transform->position.x - transform->width * transform->scale > Game::width +10
		|| transform->position.x + transform->width * transform->scale < -10
		|| transform->position.y - transform->height * transform->scale > Game::height + 10
		|| transform->position.y + transform->width * transform->scale < -10) {
		entity->destroy();
	}
}
