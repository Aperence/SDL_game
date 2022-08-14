#include "ECS/Manager.h"

void Manager::update() 
{
	for (auto& e : entities) e->update();
}

void Manager::render()
{
	for (auto& e : entities) e->render();
}

void Manager::refresh()
{
	for (auto& e : waiting_list) entities.emplace_back(move(e));
	waiting_list.clear();
	entities.erase(
		remove_if(entities.begin(), entities.end(), [](const unique_ptr<Entity>& entity) {
			return !entity->isActive();
			})
		, entities.end()
				);
}

void Manager::checkCollisions()
{
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

Entity& Manager::addEntity()
{
	Entity* e = new Entity();
	unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(move(uPtr));

	return *e;
}

Entity& Manager::pushEntity()
{
	Entity* e = new Entity();
	unique_ptr<Entity> uPtr{ e };
	waiting_list.emplace_back(move(uPtr));

	return *e;
}
