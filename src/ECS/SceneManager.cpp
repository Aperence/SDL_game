#include "ECS/SceneManager.h"

SceneManager *SceneManager::scmanager = new SceneManager();

SceneManager::SceneManager()
{
	manager = new Manager();
}

SceneManager::~SceneManager()
{
	delete manager;
}

SceneManager* SceneManager::getSceneManager()
{
	return scmanager;
}


void SceneManager::update()
{
	getSceneManager()->getManager()->refresh();
	getSceneManager()->getManager()->update();
	getSceneManager()->getManager()->checkCollisions();
}
void SceneManager::render()
{
	getSceneManager()->getManager()->render();
};


Manager* SceneManager::getManager()
{
	return scmanager->manager;
}


Manager* Scene::manager() { 
	return SceneManager::getSceneManager()->getManager(); 
}

Scene::Scene()
{
}
