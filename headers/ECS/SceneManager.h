#pragma once

#include "Manager.h"

class SceneManager;

class Scene {
public:
	Scene();
	virtual void addEntity() {};
	Manager* manager();
};

class SceneManager {
private:
	SceneManager();
	~SceneManager();

	Manager* manager;
	static SceneManager *scmanager;

public:

	static SceneManager* getSceneManager();
	Manager* getManager();
	unique_ptr<Scene> actualScene = nullptr;


	template<typename T>
	inline void addSceneHelp() {
		manager->clear();
		unique_ptr<T> uPtr = make_unique<T>();
		uPtr->addEntity();
		actualScene = move(uPtr);
	};

	template<typename T>
	inline static void addScene() {
		getSceneManager()->addSceneHelp<T>();
	};

	static void update();
	static void render();

};

