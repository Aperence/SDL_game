
#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL.h"
#include "SDL_image.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void render(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest) {
		SDL_RenderCopy(Game::renderer, tex, &src, &dest);
	}
};

#endif // !TEXTURE_H

