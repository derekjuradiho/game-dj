#include "AsteroidList.h"

AsteroidList::AsteroidList()
{
}

AsteroidList::AsteroidList(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

AsteroidList::~AsteroidList()
{
}

void AsteroidList::spawnAsteroid()
{
	//Go through all asteroids that are inside the vector. 
	for (auto asteroid = asteroidArray.begin(); asteroid != asteroidArray.end(); asteroid++)
	{
		//if the current asteroid is not active, we will initialize it and stop processing the rest of the function
		if (!asteroid->isActive)
		{
			asteroid->initialize();
			return;
		}
	}

	//execution will get here if no inactive asteroids are found. here we will add a new asteroid to the vector
	asteroidArray.emplace_back(Asteroid(renderer));

}

void AsteroidList::update()
{
	//Go through all asteroids that are inside the vector. 
	for (auto asteroid = asteroidArray.begin(); asteroid != asteroidArray.end(); asteroid++)
	{
		//if the current asteroid is active, we will move it
		if (asteroid->isActive)
		{
			asteroid->move();
		}
	}
}


void AsteroidList::draw()
{
	std::cout << "        " << asteroidArray.size() << std::endl;

	//Go through all asteroids that are inside the vector. 
	for (auto asteroid = asteroidArray.begin(); asteroid != asteroidArray.end(); asteroid++)
	{
		//if the current asteroid is active, we will draw it
		if (asteroid->isActive)
		{
			asteroid->draw(renderer);
		}
	}
}

