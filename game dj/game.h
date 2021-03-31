#ifndef __GAME__
#define __GAME__

#include "SDL.h"
#include "Sprite.h"
#include "player.h"
#include "BulletList.h"
#include "smoke.h"
#include "AsteroidList.h"
#include "CollisionManager.h"

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
	
	player cboy;
	Sprite background;
	BulletList bullets;
	Smoke smoke;
	bool animateSmoke = true;
	AsteroidList asteroids;
	CollisionManager collisionManager;

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

	float asteroidSpawnTimer = 0;
	float asteroidSpawnInterval = 3;



	void asteroidSpawner();

};

#endif 
