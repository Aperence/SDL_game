#pragma once
#include "ECS/Components.h"
#include "Game.h"
#include "Bullet.h"
#include "WavingBullet.h"

#define N_BULLET 24



class BulletSpawner : public Behaviour {
private:
	Manager* manager = nullptr;


public:
	
	BulletSpawner() = default;

	BulletSpawner(Manager *m) {
		manager = m;
	}

	void update() {
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

	};

};