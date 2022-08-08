#pragma once
#include "ECS.h"
#include "SDL.h"
#include "TextureManager.h"

class SpriteComponent : public Component {
private:
	PositionComponent *position;
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
		position = &entity->getComponent<PositionComponent>();
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
		destRect.x = position->x();
		destRect.y = position->y();
	}

	void render() override {
		SDL_RenderCopy(Game::renderer, tex, &srcRect, &destRect);
	}
};