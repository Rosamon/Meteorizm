#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position):
isAlive(true)
{
	enemyUFOsprite.setPosition(position);
	level = 3;
}

void Enemy::punched()
{
	if (ishit)
	{
		enemyUFOsprite.setColor(Color::Red);
		level--;
		ishit = false;
	}
	else
	{
		enemyUFOsprite.setColor(Color::White);
	}
}

void Enemy::aim()
{
	//
}