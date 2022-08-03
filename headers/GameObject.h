#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SDL.h"
#include "SDL_image.h"


class GameObject {
public:
	GameObject(const char* texturePath, SDL_Renderer* ren, int x, int y);
	~GameObject();
	void initSrcRect(int x, int y, int w, int h) {
		srcRect = { x,y,w,h };
	};
	void initDestRect(int x, int y, int w, int h) {
		destRect = { x,y,w,h };
	};
	void update();
	void render();

protected:

	int xpos, ypos;
	SDL_Rect srcRect, destRect;
	SDL_Texture* objTexture;
	SDL_Renderer* renderer;
};

#endif // !GAMEOBJECT_H

