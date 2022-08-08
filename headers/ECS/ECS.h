#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <vector>
#include <array>
#include <bitset>
#include <algorithm>
#include <memory>

using namespace std;

class Entity;
class Component;

using ComponentTypeID = size_t;

inline ComponentTypeID getComponentTypeID() {
	static ComponentTypeID lastID = 0;
	return lastID++;
}

template<typename T> inline ComponentTypeID getComponentTypeID() noexcept {
	static ComponentTypeID typeID = getComponentTypeID();
	return typeID;
}

constexpr size_t maxComponents = 32;

using ComponentArray = array<Component*, maxComponents>;
using ComponentBitSet = bitset<maxComponents>;

class Component {
public:
	Entity* entity;

	virtual void init(){}
	virtual void update(){}
	virtual void render(){}

	virtual ~Component(){}
};

class Entity {

private:
	bool active = true;
	vector<unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	void update() {
		for (auto& c : components) c->update();
	}
	void render() {
		for (auto& c : components) c->render();
	}
	void destroy() { active = false; }
	bool isActive() { return active; }

	template<typename T> bool hasComponent() const {
		return componentBitSet[getComponentTypeID<T>()];
	};

	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... args) {
		T* c(new T(forward<TArgs>(args)...));
		c->entity = this;
		unique_ptr<Component> uPtr{ c };
		components.emplace_back(move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	template<typename T>
	T& getComponent() const {
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

};

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
			remove_if(entities.begin(), entities.end(), [](const unique_ptr<Entity> &entity) {
				return !entity->isActive();
				})
			, entities.end()
					);
	}
	Entity& addEntity() {
		Entity* e = new Entity();
		unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(move(uPtr));

		return *e;
	}
};


#endif

