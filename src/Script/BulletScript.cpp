#include "Script/BulletScript.h"

 BulletScript::BulletScript(double angle, double speed, float xpos, float ypos) {
	 this->angle = angle;
	 this->speed = speed;
	 x = xpos;
	 y = ypos;
}

 void BulletScript::init() {
	 entity->addComponent<TransformComponent>(x, y, 258, 258, 0.08);
	 entity->addComponent<SpriteComponent>("assets/bullet.png");
	 entity->addComponent<ColliderComponent>();
	 transform = &entity->getComponent<TransformComponent>();
	 transform->speed = (float)speed;
 };

 void BulletScript::update() {
	 fps++;
	 transform->velocity = Vector2D((float)cos(angle * M_PI / 180.0), (float)sin(angle * M_PI / 180.0)) * speed;
	 int x = transform->position.x;
	 int y = transform->position.y;
	 int w = transform->width;
	 int h = transform->height;
	 int scale = transform->scale;
	 if (x > Game::width + w * scale / 2.0 || x < 0 - w * scale / 2.0 || y > Game::height + h * scale / 2.0 || y < 0 - h * scale / 2.0) {
		 entity->destroy();
	 }
 };