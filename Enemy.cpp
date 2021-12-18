#include "Enemy.h"

// 1, 2, 3
Enemy::Enemy(int position):
alive(true)
{
	switch (position)
	{
		case 3:
			position_UFO.x = 100;
			position_UFO.y = 100;
			break;
		case 2:
			position_UFO.x = 300;
			position_UFO.y = 100;
			break;
		default:
			position_UFO.x = 500;
			position_UFO.y = 100;
			break;
	}

	enemyUFOsprite.setPosition(position_UFO);
	level = 3;
	
	enemytexture.loadFromFile("Kursa4.png");
	enemyUFOsprite.setTexture(enemytexture);
	enemyUFOsprite.setTextureRect(sf::IntRect(416, 45, 73, 48));
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

Bullet Enemy::aim(sf::Vector2f position)
{
	Bullet enemyBullet(position_UFO, 270 * 3.14159f / 180.0f);
	return enemyBullet;


bool Enemy::move(float frametime)
{
	//
	sf::Vector2f position = enemyUFOsprite.getposition();
	if (position_UFO.x >= 500)
	{
		direction.x = -1;
	}
	if (position_UFO.x <= 50)
	{
		direction.x = 1;
	}
	if (trunc(position_UFO.x) == 299 || trunc(position_UFO.x) == 300)
	{
		short buff = 0;
		buff = rand() % 2;
		if (buff == 1)
		{
			direction.x = -1;
		}
		else
		{
			direction.x = 1;
		}
	}
	sf::Vector2f distance = direction * 0.1 * frametime;
    enemyUFOsprite.move(distance);
    position_UFO += distance;
    if (trunc(position_UFO.x) >= 500 || trunc(position_UFO.x) == 299 || trunc(position_UFO.x) == 300 || trunc(position_UFO.x) == 50)
    {
    	direction.x = 0;
    	return false;
    }
    return true;
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(enemyUFOsprite);
}