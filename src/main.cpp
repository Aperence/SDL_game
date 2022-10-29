#include <SDL.h>
#include "SDL_thread.h"
#include "Game.h"

SDL_Thread* thread;

SDL_cond* ready;
SDL_cond* done;

Game* game;

const int FPS = 60;
const int FrameDelay = 1000 / 60;

int threads_loop(void *ptr) {

	SDL_mutex* m = SDL_CreateMutex();

	while (game->running()) {
		SDL_CondWait(ready, m);

		// can optimize with more threads
        game->update();

		SDL_CondSignal(done);
	}

	SDL_DestroyMutex(m);
	return 0;
}

int main(int argc, char** argv) {

	game = new Game();

	game->init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 450, false);

	ready = SDL_CreateCond();
	done = SDL_CreateCond();
	
	Uint32 FrameStart;
	int FrameTime;

	SDL_mutex *m = SDL_CreateMutex();

	while (game->running()) {

		FrameStart = SDL_GetTicks();

		game->handleEvents();
		SDL_CondBroadcast(ready);
		game->update();
		SDL_CondWait(done, m);
		game->render();

		FrameTime = SDL_GetTicks() - FrameStart;

		if (FrameDelay > FrameTime) {
			SDL_Delay(FrameDelay - FrameTime);
		}
	}

	SDL_WaitThread(thread, NULL);
	SDL_DestroyCond(ready);
	SDL_DestroyCond(done);
	SDL_DestroyMutex(m);

	game->clean();

	delete game;

	return 0;

}