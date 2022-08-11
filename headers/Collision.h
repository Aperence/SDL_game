#pragma once
#include "SDL.h"

class Collision {
public:
	static bool AABB(SDL_Rect& recA, SDL_Rect& recB);
};