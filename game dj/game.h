#ifndef __GAME__
#define __GAME__

#include "SDL.h"
#include "Sprite.h"
#include "player.h"
#include "BulletList.h"
#include "enemy.h"

class Game
{

public:

	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void prepare();

	void handleEvents();
	void update();
	void render();
	void waitForNextFrame();

	void cleanup();

	bool running() { return m_bRunning; }
private:
	enemy zombie;
	player cboy;
	Sprite background;
	BulletList bullets;


	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	int targetFramerate = 30;
	int frameDelayMs = 1000 / targetFramerate;

	Uint32 currentFrameEndTime;
	Uint32 currentFrameStartTime;
	Uint32 timeSinceLastFrame;

	float deltaTime;

	float gameTime = 0;
};

#endif 
