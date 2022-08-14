#ifndef BULLET_H
#define BULLET_h

#include "ECS/ECS.h"
#include "ECS/Components.h"
#include <math.h>


class BulletScript : public Behaviour {
private:
	double angle = 0.0;
	TransformComponent* transform = nullptr;
	const char* sprite = "assets/bullet.png";
	double speed = 2.0;
	int fps;
	float x, y;

public:
	BulletScript() = default;
	BulletScript(double angle, double speed, float xpos, float ypos) {
		this->angle = angle;
		this->speed = speed;
		x = xpos;
		y = ypos;
	};

	void init() {
		entity->addComponent<TransformComponent>(x, y, 258, 258, 0.08);
		entity->addComponent<SpriteComponent>("assets/bullet.png");
		transform = &entity->getComponent<TransformComponent>();
		transform->speed = (float) speed;
	};

	void update() {
		fps++;
		transform->velocity = Vector2D((float) cos(angle * M_PI / 180.0), (float) sin(angle * M_PI / 180.0)) * speed;
		int x = transform->position.x;
		int y = transform->position.y;
		int w = transform->width;
		int h = transform->height;
		int scale = transform->scale;
		if (x > Game::width + w * scale / 2.0 || x < 0 - w * scale / 2.0 || y > Game::height + h * scale / 2.0 || y < 0 - h * scale / 2.0) {
			entity->destroy();
		}
	};
};
#endif