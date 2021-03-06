#include "BulletList.h"

BulletList::BulletList() {}
BulletList::~BulletList() {}

void BulletList::AddBullet(SDL_Renderer* renderer, int x, int y)
{
	bulletArray.emplace_back(Bullet(renderer, x, y));
}

void BulletList::UpdateBullets(SDL_Renderer* renderer)
{
	for (auto it = bulletArray.begin(); it != bulletArray.end();) {
		it->update();
		if (it->outOfScreen())
		{
			it = bulletArray.erase(it);
		}
		else
		{
			it->draw(renderer);
			++it;
		}
	}
}