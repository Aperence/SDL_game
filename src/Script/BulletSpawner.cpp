#include "Script/BulletSpawner.h"
#include "Script/Polygon.h"

BulletSpawner::BulletSpawner(Manager* m)
{
	manager = m;
}

void BulletSpawner::update()
{
	Phase2();
};

void BulletSpawner::Phase1() {
	if (Game::fps % 120 == 0) {
		int x = rand() % 600 + 50;
		int y = rand() % 400 + 50;
		int type = rand() % 2;
		for (size_t i = 0; i < N_BULLET; i++)
		{
			Entity& e = manager->pushEntity();
			if (type == 0) {
				e.addBehaviour<BulletScript>(i * (360.0 / N_BULLET), 1.0, x, y);
			}
			else {
				e.addBehaviour<WavingBulletScript>(i * (360.0 / N_BULLET), 1.0, x, y);
			}
		}
	}
}

void BulletSpawner::Phase2() {
	if (Game::fps % 120 == 0) {
		int x = rand() % 600 + 50;
		int rotation_speed = rand() % 45 + 50;
		int nb_sides = rand() % 5 + 4;
		Entity& e = manager->pushEntity();
		e.addBehaviour<Polygon>(Vector2D(x, 0), Vector2D(0, 1), 2, nb_sides, rotation_speed, 30+5*(nb_sides/6), manager, 5 - nb_sides/7);
	}
}