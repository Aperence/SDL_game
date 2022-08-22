#ifndef SPRITE_COMPO_H
#define SPRITE_COMPO_H

#include "ECS.h"
#include "SDL.h"
#include "TextureManager.h"
#include "Game.h"
#include "Components.h"

class SpriteComponent : public Component {
private:
	TransformComponent* transform;
	SDL_Texture *tex;
	SDL_Rect srcRect, destRect;

public:

	bool display = true;

	SpriteComponent() = default;
	SpriteComponent(const char* path);

	~SpriteComponent();

	void setTex(const char* path);

	void init() override;

	void setSrc(int w, int h);

	void setDest(int w, int h);

	void update() override;

	void render() override;
};
#endif