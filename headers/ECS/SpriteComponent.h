#ifndef SPRITE_COMPO_H
#define SPRITE_COMPO_H

#include "ECS.h"
#include "SDL.h"
#include "TextureManager.h"
#include "Game.h"

class SpriteComponent : public Component {
private:
	TransformComponent* position;
	SDL_Texture *tex;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		setTex(path);
	}
	void setTex(const char* path) {
		tex = TextureManager::LoadTexture(path);
	}

	void init() override {
		srcRect = { 0,0,32,32 };
		destRect = { 0,0,64,64 };
		position = &entity->getComponent<TransformComponent >();
	}

	void setSrc(int w, int h) {
		srcRect.w = w;
		srcRect.h = w;
	}

	void setDest(int w, int h) {
		destRect.w = w;
		srcRect.h = h;
	}

	void update() override {
		destRect.x = position->position.x;
		destRect.y = position->position.y;
	}

	void render() override {
		TextureManager::render(tex, srcRect, destRect);
	}
};
#endif