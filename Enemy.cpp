#pragma once
#include "Enemy.h"
// 1, 2, 3
Enemy::Enemy(int position)
{
	is_Alive = true;
	switch (position)
	{
		case 3:
			position_UFO.x = 100;
			position_UFO.y = 50;
			direction.x = 1;
			break;
		case 2:
			position_UFO.x = 400;
			position_UFO.y = 50;
			direction.x = -1;
			break;
		default:
			position_UFO.x = 900; // c учетом того что поле в ширину 1000
			position_UFO.y = 50;
			direction.x = -1;
			break;
	}

	enemyUFOsprite.setPosition(position_UFO);
	level = 10; // количество попаданий для уничтожения
	TouchBox = sf::FloatRect(position_UFO.x, position_UFO.y, 70, 45);
	enemytexture.loadFromFile("images\\Kursa4.png");
	enemyUFOsprite.setTexture(enemytexture);
	enemyUFOsprite.setTextureRect(sf::IntRect(416, 45, 70, 47));
}

void Enemy::punched()
{
	if (this == nullptr)
		return;// если указатель на этот объект пуст, то выход из метода
	if (ishit)
	{
		enemyUFOsprite.setColor(sf::Color::Red);
		level--;
		if (level < 0)
		{
			level = 0;
		}
		ishit = false;
	}
	else
	{
		enemyUFOsprite.setColor(sf::Color::White);
	}
	if (level == 0)
	{
		is_Alive = false;
	}
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
		break;
	default:
		break;
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
	if (this == nullptr)
		return false;
	sf::Vector2f position = position_UFO;
	if (position_UFO.x >= 899)
	{
		direction.x = -1;
	}
	if (position_UFO.x <= 51)
	{
		direction.x = 1;
	}
	if (trunc(position_UFO.x) == 499 || trunc(position_UFO.x) == 500)
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
	sf::Vector2f distance = direction * 0.1f * frametime;
    enemyUFOsprite.move(distance);
	TouchBox.left = enemyUFOsprite.getPosition().x;//движение вместе со спрайтом
	TouchBox.top = enemyUFOsprite.getPosition().y;
    position_UFO += distance;
    return true;
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(enemyUFOsprite);
}

void Enemy::update(float frametime)
{
	punched();
	moved(frametime);	
}

bool Enemy::checkPoint(sf::Vector2f point) {
	if (this == nullptr)
		return false;

	float ax = position_UFO.x + 40;
	float ay = position_UFO.y + 40;

	float px = point.x;
	float py = point.y;

	float sqrDistance = ((ax - point.x)*(ax - point.x)) + ((ay - point.y) * (ay - point.y));
	float sqrRadius = 25*25;

	return (sqrDistance <= sqrRadius);
}