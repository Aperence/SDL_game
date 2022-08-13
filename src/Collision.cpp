#include "Collision.h"

bool Collision::AABB(SDL_Rect& recA, SDL_Rect& recB)
{
	return recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y;
}
