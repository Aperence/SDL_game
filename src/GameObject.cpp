#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(const char* texturePath, int x, int y) {
	xpos = x;
	ypos = y;
	objTexture = TextureManager::LoadTexture(texturePath);
	Game::addObject(this);
}

void GameObject::update() {
	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

GameObject::~GameObject() {
	SDL_DestroyTexture(objTexture);
}

