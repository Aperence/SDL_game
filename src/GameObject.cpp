#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturePath, SDL_Renderer* ren, int x, int y) {
	xpos = x;
	ypos = y;
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturePath, ren);


}

void GameObject::update() {
	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

GameObject::~GameObject() {
	SDL_DestroyTexture(objTexture);
}

