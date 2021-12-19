#include "Asteroids.h"

Asteroid::Asteroid(int level) : is_Alive(true), level(level) {
     //скорости и размеры Астероида
     float speed[3] = { 0.03f, 0.05f, 0.07f };
     int radius[3] = { 37.5, 37.5, 18};

     Image AsterImage;
     AsterImage.loadFromFile("images/Kursa4.png");
     AsteroidTexture.loadFromImage(AsterImage);
     AsterSprite = Sprite(AsteroidTexture, IntRect(38, 38, 75, 75)); // целый
     AsterSprite.setOrigin(radius[level], radius[level]);
    
    int angle = 270 % 360; // угол в 270 градусов, задаем направление строго вниз
    direction = Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));

    int x = radius[level] + rand() % (800 - radius[level]); // 800 - предполагаемая ширина окна
    int y = radius[level] + rand() % 100; // 100 - первые сто px сверху окна

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
    //здесь меняем картинки и радиус
    int radius[3] = { 37.5, 37.5, 18 };
    switch (level)
    {
    case 1: {
        AsterSprite = Sprite(AsteroidTexture, IntRect(128, 38, 75, 75)); // коцаный
        AsterSprite.setOrigin(radius[level], radius[level]);
        break;
    }
    case 2: {
        AsterSprite = Sprite(AsteroidTexture, IntRect(58, 155, 36, 36)); // предсмертный
        AsterSprite.setOrigin(radius[level], radius[level]);
        break;
    }
    };

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
    //здесь 600 - высота окна
    if (position.y > (600 - radius[level])) {
        delete this;
    }
    setPosition(position);
}