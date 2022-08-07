#include "TextureManager.h"
#include "Game.h"

using namespace std;

SDL_Texture* TextureManager::LoadTexture(const char* fileName) {
	SDL_Surface* tempSurf = IMG_Load(fileName);

	SDL_Texture* ret = SDL_CreateTextureFromSurface(Game::renderer, tempSurf);

	SDL_FreeSurface(tempSurf);

	cout << "Rendered texture " << fileName << endl;

	return ret;
}