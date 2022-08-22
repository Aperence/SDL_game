#ifndef MANAGER_H
#define MANAGER_H

#include "Components.h"

class Manager {
private:
	vector<unique_ptr<Entity>> entities;
	vector<unique_ptr<Entity>> waiting_list;

public:
	void update();
	void render();
	void refresh();
	void checkCollisions();

	Entity& addEntity();

	Entity& pushEntity();


};

#endif