#include "ECS/KeyboardController.h"

void KeyboardController::update()
{
	for (auto& s : entity->scripts) s->handleInput(Game::event);
}
