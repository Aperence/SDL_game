#include "Script/WavingBullet.h"

WavingBulletScript::WavingBulletScript(double angle, double speed, float xpos, float ypos)
{
	this->angle = angle;
	this->speed = speed;
	center = Vector2D(xpos, ypos);
}
void WavingBulletScript::init()
{
	entity->addComponent<TransformComponent>(center.x, center.y, 258, 258, 0.08);
	entity->addComponent<SpriteComponent>("assets/bullet.png");
	entity->addComponent<ColliderComponent>();
	transform = &entity->getComponent<TransformComponent>();
	transform->speed = (float)speed;
	entity->getComponent<SpriteComponent>().display = false;
}
void WavingBulletScript::update()
{
	fps++;
	entity->getComponent<SpriteComponent>().display = true;
	Vector2D oscillation = Vector2D((float)fps * speed, oscillationSize * sin(M_PI * fps / period));

	oscillation += center;
	oscillation.rotate(angle, center);

	transform->position = oscillation;

	int x = transform->position.x;
	int y = transform->position.y;
	int w = transform->width;
	int h = transform->height;
	int scale = transform->scale;
	if (x > Game::width + w * scale / 2.0 || x < 0 - w * scale / 2.0 || y > Game::height + h * scale / 2.0 || y < 0 - h * scale / 2.0) {
		entity->destroy();
	}
}
