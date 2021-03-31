#include "Asteroid.h"

SDL_Rect Asteroid::getRect()
{
	return dst;
}

Asteroid::Asteroid()
{
}

Asteroid::~Asteroid()
{
}

void Asteroid::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pAsteroidTex, &src, &dst);
}

void Asteroid::cleanup()
{
}

void Asteroid::move()
{
	dst.y += velY;
	if (dst.y >= 480)
	{
		initialize();
	}

}

void Asteroid::initialize()
{
	isActive = true;

	int randomSize = 30 + rand() % 30;
	velY = 1 + rand() % 6;


	dst.x = rand() % 640 - randomSize;
	dst.y = -randomSize;
	dst.w = randomSize;
	dst.h = randomSize;
}

Asteroid::Asteroid(SDL_Renderer* renderer)
{
	pAsteroidTex = IMG_LoadTexture(renderer, "asteroid.png");

	SDL_QueryTexture(pAsteroidTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	initialize();
}

