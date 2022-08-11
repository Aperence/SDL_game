#include "Collision.h"

bool Collision::AABB(SDL_Rect& recA, SDL_Rect& recB)
{
	return ((recB.x <= recA.x) && (recA.x <= recB.x + recB.w)
		|| (recA.x <= recB.x) && (recB.x <= recA.x + recA.w))
		&&
		((recB.y <= recA.y) && (recA.y <= recB.y + recB.h)
			|| (recA.y <= recB.y) && (recB.y <= recA.y + recA.h));
}
