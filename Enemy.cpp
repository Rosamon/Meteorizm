#include "Enemy.h"

// 1, 2, 3
Enemy::Enemy(int position):
alive(true)
{
	switch (position)
	{
		case 3:
			position_UFO.x = 100;
			position_UFO.y = 50;
			break;
		case 2:
			position_UFO.x = 400;
			position_UFO.y = 50;
			break;
		default:
			position_UFO.x = 900; // c учетом того что поле в ширину 1000
			position_UFO.y = 50;
			break;
	}

	enemyUFOsprite.setPosition(position_UFO);
	level = 4;
	
	enemytexture.loadFromFile("Kursa4.png");
	enemyUFOsprite.setTexture(enemytexture);
	enemyUFOsprite.setTextureRect(sf::IntRect(416, 45, 70, 47));
}

void Enemy::punched()
{
	
	if (ishit)
	{
		enemyUFOsprite.setColor(Color::Red);
		level--;
		if (level < 0)
		{
			level = 0;
		}
		ishit = false;
	}
	else
	{
		enemyUFOsprite.setColor(Color::White);
	}
	if (level == 0)
	{
		alive = false;
	}
}

Bullet Enemy::aim(sf::Vector2f position)
{
	sf::Vector2f gunPosition = position_UFO;
	gunPosition.x += 40;
	gunPosition.y += 40;
	sf::Vector2f vec = position - gunPosition;// вектор в направлении героя
	Bullet enemyBullet(gunPosition, atan2(vec.y, vec.x)*180/3.14159, true);
	return enemyBullet;
}


bool Enemy::moved(float frametime)
{
	//
	sf::Vector2f position = enemyUFOsprite.getposition();
	if (position_UFO.x >= 899)
	{
		direction.x = -1;
	}
	if (position_UFO.x <= 51)
	{
		direction.x = 1;
	}
	if (trunc(position_UFO.x) == 399 || trunc(position_UFO.x) == 400)
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
    return true;
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(enemyUFOsprite);
}

void Enemy::update(float frametime)
{
	if (this != nullptr)
	{
		punched();
		moved(frametime);
		switch (level)
		{
		case 0:
			enemyUFOsprite.setTextureRect(sf::IntRect(107, 122, 96, 95));
			break; 
		case 1:
			enemyUFOsprite.setTextureRect(sf::IntRect(515, 45, 70, 47));
			break;
		case 2:
			enemyUFOsprite.setTextureRect(sf::IntRect(608, 45, 70, 47));
			//
			break;
		default:
			break;
		}
	}
}

bool Enemy::checkPoint(sf::Vector2f point) {
	if (this != nullptr)
	{
		float ax = position_UFO.x + 40;
		float ay = position_UFO.y + 40;

		float px = point.x;
		float py = point.y;

		float sqrDistance = ((ax - point.x)*(ax - point.x)) + ((ay - point.y) * (ay - point.y));
		float sqrRadius = 25*25;

		return (sqrDistance <= sqrRadius);
	}
	return false;
}