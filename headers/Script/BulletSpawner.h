#pragma once
#include "ECS/Components.h"
#include "Game.h"
#include "BulletScript.h"
#include "WavingBullet.h"

#define N_BULLET 24



class BulletSpawner : public Behaviour {
private:
	Manager* manager = nullptr;


public:
	
	BulletSpawner() = default;

	BulletSpawner(Manager* m);

	void update();

	void Phase1();

	void Phase2();

};