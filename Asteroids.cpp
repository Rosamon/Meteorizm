#include "Asteroids.h"

Asteroid::Asteroid(int level) : is_Alive(true), level(level) {
     //�������� � ������� ���������
     float speed[3] = { 0.03f, 0.05f, 0.07f };
     int radius[3] = { 37.5, 37.5, 18};

     Image AsterImage;
     AsterImage.loadFromFile("images/Kursa4.png");
     AsteroidTexture.loadFromImage(AsterImage);
     AsterSprite = Sprite(AsteroidTexture, IntRect(38, 38, 75, 75)); // �����
     AsterSprite.setOrigin(radius[level], radius[level]);
    
    int angle = 270 % 360; // ���� � 270 ��������, ������ ����������� ������ ����
    direction = Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));

    int x = radius[level] + rand() % (800 - radius[level]); // 800 - �������������� ������ ����
    int y = radius[level] + rand() % 100; // 100 - ������ ��� px ������ ����

    Vector2f position(x, y);
    setPosition(position);    
    
}


Asteroid::~Asteroid() {
}



bool Asteroid::checkPoint(sf::Vector2f point) {
    float ax = getPosition().x;
    float ay = getPosition().y;

    float px = point.x;
    float py = point.y;

    int radius[3] = { 37.5, 37.5, 18 };
    float sqrDistance = ((ax - px) * (ax - px)) + ((ay - py) * (ay - py));
    float sqrRadius = radius[level] * radius[level];

    return (sqrDistance <= sqrRadius);
}



bool Asteroid::isAlive() {
    return is_Alive;
}

int Asteroid::getLevel() {
    return level;
}


void Asteroid::breakDown() {
    level++;

    if (level > 2) {
        is_Alive = false;
        return;
    }
    //����� ������ �������� � ������
    int radius[3] = { 37.5, 37.5, 18 };
    switch (level)
    {
    case 1: {
        AsterSprite = Sprite(AsteroidTexture, IntRect(128, 38, 75, 75)); // �������
        AsterSprite.setOrigin(radius[level], radius[level]);
        break;
    }
    case 2: {
        AsterSprite = Sprite(AsteroidTexture, IntRect(58, 155, 36, 36)); // ������������
        AsterSprite.setOrigin(radius[level], radius[level]);
        break;
    }
    }

    float angle = 90 % 360;
    direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));
}

void Asteroid::update() {
    if (!is_Alive) return;

    AsterSprite.rotate(15);

    float speed[3] = { 0.03f, 0.05f, 0.07f };
    sf::Vector2f distance = direction * speed[level] * 60.0f;
    move(distance);

    sf::Vector2f position = getPosition();
    int radius[3] = { 37.5, 37.5, 18 };
    //����� 600 - ������ ����
    if (position.y > (600 - radius[level])) {
        delete this;
    }
    setPosition(position);
}