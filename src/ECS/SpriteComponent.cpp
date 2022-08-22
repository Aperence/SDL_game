#include "ECS/SpriteComponent.h"

SpriteComponent::SpriteComponent(const char* path)
{
	setTex(path);
}

SpriteComponent::~SpriteComponent()
{
	SDL_DestroyTexture(tex);
}

void SpriteComponent::setTex(const char* path)
{
	tex = TextureManager::LoadTexture(path);
}

void SpriteComponent::init()
{
	transform = &entity->getComponent<TransformComponent >();
	srcRect = { 0,0, transform->width, transform->height };
	destRect = { 0,0,static_cast<int>(transform->width * transform->scale),static_cast<int>(transform->height * transform->scale) };
}

void SpriteComponent::setSrc(int w, int h)
{
	srcRect.w = w;
	srcRect.h = w;
}

void SpriteComponent::setDest(int w, int h)
{
	destRect.w = w;
	destRect.h = h;
}

void SpriteComponent::update()
{
	destRect.x = (int)transform->position.x;
	destRect.y = (int)transform->position.y;
}

void SpriteComponent::render()
{
	if (!display) return;
	TextureManager::render(tex, srcRect, destRect);
}
