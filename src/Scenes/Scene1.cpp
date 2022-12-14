#include "Scenes/Scene1.h"
#include "ECS/Components.h"
#include "Script/MovableBullet.h"
#include "Script/BulletSpawner.h"
#include "Script/Polygon.h"
#include "Game.h"

void Scene1::addEntity()
{
	auto& bullet = manager()->addEntity();
	auto& bulletSpawner = manager()->addEntity();
	auto& bulletSpawner2 = manager()->addEntity();
	auto& bulletSpawner3 = manager()->addEntity();
	auto& bulletSpawner4 = manager()->addEntity();


	float half = 258.0 * 0.125 / 2.0;
	bullet.addComponent<TransformComponent>(Game::width / 2 - half, Game::height / 2 - half, 258, 258, 0.125);
	bullet.addComponent<SpriteComponent>("assets/bullet.png");
	bullet.addBehaviour<MovableBulletScript>();
	bullet.addComponent<KeyboardController>();
	bullet.addComponent<ColliderComponent>();

	//bulletSpawner.addBehaviour<BulletSpawner>(manager());
	bulletSpawner.addBehaviour<Polygon>(Vector2D(200,200), Vector2D(1, 0), 1, 3, 90, 50, manager(), 3);
	bulletSpawner2.addBehaviour<Polygon>(Vector2D(200, 100), Vector2D(1, 0), 1, 3, 90, 50, manager(), 3);
	bulletSpawner3.addBehaviour<Polygon>(Vector2D(200, 300), Vector2D(1, 0), 1, 3, 90, 50, manager(), 3);
	bulletSpawner4.addBehaviour<Polygon>(Vector2D(200, 400), Vector2D(1, 0), 1, 3, 90, 50, manager(), 3);

}
