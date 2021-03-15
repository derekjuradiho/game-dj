#include "Game.h"
#include <iostream>


Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);



		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}


		return true;
	}

	return false;

}

void Game::prepare()
{
	background = Sprite(m_pRenderer, "bluecavern.bmp", 0, 0, 640, 480, 0, 0, 640, 480);
	cboy = player(m_pRenderer, "sprite.bmp", 70, 70);
	zombie = enemy(m_pRenderer, "zombie.bmp", 70, 70);
	bullets = BulletList();

	deltaTime = 1.0f / targetFramerate;
	currentFrameStartTime = SDL_GetTicks();

	m_bRunning = true;	
}

void Game::handleEvents()
{
	

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_bRunning = false;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				cboy.velY = -1;
				break;

			case SDLK_s:
				cboy.velY = 1;
				break;

			case SDLK_a:
				cboy.velX = -1;
				break;

			case SDLK_d:
				cboy.velX = 1;
				break;

			case SDLK_SPACE:
				bullets.AddBullet(m_pRenderer, cboy.getWeaponX(), cboy.getWeaponY());
				break;
			default:
				break;

			}

		}

		else if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				cboy.velY = 0;
				break;

			case SDLK_s:
				cboy.velY = 0;
				break;

			case SDLK_a:
				cboy.velX = 0;
				break;

			case SDLK_d:
				cboy.velX = 0;
				break;

			case SDLK_ESCAPE:
				m_bRunning = false;
				break;

			default:
				break;
			}
		}
	}
	



}

void Game::update()
{
	cboy.moveBy(cboy.velX, cboy.velY);
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	background.draw(m_pRenderer);

	zombie.draw(m_pRenderer);

	cboy.draw(m_pRenderer);

	bullets.UpdateBullets(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}

void Game::waitForNextFrame()
{
	
	Uint32 gameTimeMs = SDL_GetTicks();

	timeSinceLastFrame = gameTimeMs - currentFrameStartTime;

	if (timeSinceLastFrame < frameDelayMs)
	{
		SDL_Delay(frameDelayMs - timeSinceLastFrame);
	}

	currentFrameEndTime = SDL_GetTicks();

	deltaTime = (currentFrameEndTime - currentFrameStartTime) / 1000.f;

	gameTime = currentFrameEndTime / 1000.0f;

	currentFrameStartTime = currentFrameEndTime;
}

void Game::cleanup()
{

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

