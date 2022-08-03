#ifndef BULLET_H
#define BULLET_H
#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"

class Bullet : public GameObject {

public:
	Bullet(const char* texturePath, SDL_Renderer* ren, int x, int y):GameObject(texturePath, ren, x, y){};
	void update();

};

#endif
