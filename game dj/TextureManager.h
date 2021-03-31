#pragma once
#include "smoke.h"
#include <vector>

class TextureManager
{
private:
	TextureManager() {};
	static TextureManager* s_pInstance;

	TextureManager(TextureManager const&) {};             
	TextureManager& operator=(TextureManager const&) {}; 

	Smoke s;

public:

	static TextureManager* Instance();
	void AddSmoke(SDL_Renderer* renderer, int x, int y);
	void AnimateSmoke();
};
