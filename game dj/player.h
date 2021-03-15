#pragma once
#include <SDL_image.h>
#include <math.h>


class player
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;

public:
	SDL_Rect dst;

	
	float velX = 0;
	float velY = 0;


	player();
	player(SDL_Renderer* renderer, const char* filename,
		int w, int h);
	player(SDL_Renderer* renderer, const char* filename,
		int srcX, int srcY, int srcW, int srcH,
		int dstX, int dstY, int dstW, int dstH);


	~player();

	void setPosition(int x, int y);
	void moveBy(int x, int y);
	void draw(SDL_Renderer* renderer);

	void cleanup();

	int getWeaponX() { return dst.x + dst.w / 2; }
	int getWeaponY() { return dst.y; };

	float speed = 5.0f;
};
