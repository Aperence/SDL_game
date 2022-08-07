
#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL.h"
#include "SDL_image.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* fileName);
};

#endif // !TEXTURE_H

