#pragma once
#include "BulletList.h"
#include "AsteroidList.h"
#include "player.h"

class CollisionManager
{
	BulletList* m_pBulletList;
	AsteroidList* m_pAsteroidList;
	player* m_pplayer;


	void checkBulletToAsteroidCollisions();
	bool checkPlayerToAsteroidCollisions();



public:

	CollisionManager();
	~CollisionManager();
	CollisionManager(BulletList* bulletList, AsteroidList* asteroidList, player* player);

	bool checkCollisions();

};

