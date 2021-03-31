#pragma once
#include <SDL_image.h>
class Smoke
{
	SDL_Texture* pSpriteTex = nullptr;

	SDL_Rect src;
	SDL_Rect dst;

	SDL_Renderer* renderer;


	
	int displayFrame = 0;

	
	int frameCount = 24;


	
	int frameWidth = 32;
	int frameHeight = 32;






public:
	Smoke() { };
	Smoke(SDL_Renderer* renderer, int posX, int posY);


	~Smoke() {};

	bool animate();
	void cleanup();
};
