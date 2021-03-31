#pragma once
#include <SDL_image.h>
#include <iostream>

class Asteroid
{
	SDL_Texture* pAsteroidTex = nullptr;
	SDL_Rect src;
	SDL_Rect dst;

	int velY = 0;

public:

	bool isActive = false;

	SDL_Rect getRect();
	// constructors -- these are used when initializing an object
	Asteroid();
	Asteroid(SDL_Renderer* renderer);

	// destructor -- used when the object is to be removed from memory
	~Asteroid();

	void draw(SDL_Renderer* renderer);

	void cleanup();

	void move();
	void initialize();

};
