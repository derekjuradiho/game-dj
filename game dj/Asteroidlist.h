#pragma once
#include "Asteroid.h"
#include <vector>


class AsteroidList
{
	SDL_Renderer* renderer;


public:
	std::vector<Asteroid> asteroidArray;
	AsteroidList();
	AsteroidList(SDL_Renderer* renderer);
	~AsteroidList();

	void spawnAsteroid();
	void update();
	void draw();


};

