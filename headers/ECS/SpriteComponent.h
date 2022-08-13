#ifndef SPRITE_COMPO_H
#define SPRITE_COMPO_H

#include "ECS.h"
#include "SDL.h"
#include "TextureManager.h"
#include "Game.h"

class SpriteComponent : public Component {
private:
	TransformComponent* transform;
	SDL_Texture *tex;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		setTex(path);
	}

	~SpriteComponent() {
		SDL_DestroyTexture(tex);
	}

	void setTex(const char* path) {
		tex = TextureManager::LoadTexture(path);
	}

	void init() override {
		transform = &entity->getComponent<TransformComponent >();
		srcRect = { 0,0, transform->width, transform->height };
		destRect = { 0,0,static_cast<int>(transform->width*transform->scale),static_cast<int>(transform->height* transform->scale) };
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
		destRect.x = (int) transform->position.x;
		destRect.y = (int) transform->position.y;
	}

	void render() override {
		TextureManager::render(tex, srcRect, destRect);
	}
};
#endif