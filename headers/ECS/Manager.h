#pragma once

#include "Components.h"


class Manager {
private:
	vector<unique_ptr<Entity>> entities;
public:
	void update() {
		for (auto& e : entities) e->update();
	}
	void render() {
		for (auto& e : entities) e->render();
	}
	void refresh() {
		entities.erase(
			remove_if(entities.begin(), entities.end(), [](const unique_ptr<Entity>& entity) {
				return !entity->isActive();
				})
			, entities.end()
					);
	}
	void checkCollisions() {
		for (auto& e1 : entities)
		{
			if (!e1->hasComponent<ColliderComponent>()) continue;
			for (auto& e2 : entities) {
				if (!e2->hasComponent<ColliderComponent>()) continue;
				if (e1 == e2) continue;
				if (Collision::AABB(e1->getComponent<ColliderComponent>().collider, e2->getComponent<ColliderComponent>().collider)) {
					e1->collide(*e2);
					e2->collide(*e1);
				}
			}
		}
	}

	Entity& addEntity() {
		Entity* e = new Entity();
		unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(move(uPtr));

		return *e;
	}
};