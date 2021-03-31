#include "CollisionManager.h"

void CollisionManager::checkBulletToAsteroidCollisions()
{

	
	for (auto bullet = m_pBulletList->bulletArray.begin(); bullet != m_pBulletList->bulletArray.end(); )
	{
		bool moveToNext = true;
		
		for (auto asteroid = m_pAsteroidList->asteroidArray.begin(); asteroid != m_pAsteroidList->asteroidArray.end(); ++asteroid)
		{
			
			if (asteroid->isActive && bullet->checkCollision(asteroid->getRect()))
			{
				
				bullet = m_pBulletList->bulletArray.erase(bullet);

				moveToNext = false;


		
				asteroid->isActive = false;
				break;
			}
		}
		
		if (moveToNext)
		{
			++bullet;
		}

	}
}

bool CollisionManager::checkPlayerToAsteroidCollisions()
{

	
	for (auto asteroid = m_pAsteroidList->asteroidArray.begin(); asteroid != m_pAsteroidList->asteroidArray.end(); ++asteroid)
	{
		
		if (asteroid->isActive && m_pplayer->checkCollision(asteroid->getRect()))
		{
			
			return true;
		}
	}


	
	return false;
}

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

CollisionManager::CollisionManager(BulletList* bulletList, AsteroidList* asteroidList, player* player)
{
	m_pBulletList = bulletList;
	m_pAsteroidList = asteroidList;
	m_pplayer = player;
}

bool CollisionManager::checkCollisions()
{
	checkBulletToAsteroidCollisions();
	return checkPlayerToAsteroidCollisions();
}
