#include "Asteroids.h"


 Asteroid::Asteroid(int level) : is_Alive(true), level(level) {
    int angle = 270 % 360; // угол в 270 градусов, задаем направление строго вниз
    direction = Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));

    int x = rand() % 400; // 400 - предполагаемая ширина окна
    int y = rand() % 100; // 100 - первые сто px сверху окна

    //скорости и размеры Астероида
    float speed[3] = { 0.03f, 0.05f, 0.07f };
    int radius[3] = { 75, 75, 36 };

    Vector2f position(x, y);
    setPosition(position);


  


    Image AsterImage;
    AsterImage.loadFromFile("images/Kursa4.png");
    Texture AsteroidTexture;
    AsteroidTexture.loadFromImage(AsterImage);
    Sprite AsterSprite(AsteroidTexture, IntRect(38, 38, 75, 75)); // целый
    
}


Asteroid::~Asteroid() {
}

bool Asteroid::isAlive() {
    return is_Alive;
}


int Asteroid::getLevel() {
    return level;
} 

bool Asteroid::checkPoint(sf::Vector2f point) {
    float ax = getPosition().x;
    float ay = getPosition().y;

    float px = point.x;
    float py = point.y;

    int radius[3] = { 75, 75, 36 };
    float sqrDistance = ((ax - px) * (ax - px)) + ((ay - py) * (ay - py));
    float sqrRadius = radius[level] * radius[level];

    return (sqrDistance <= sqrRadius);
}


void Asteroid::breakDown() {
    level++;

    if (level > 2) {
        is_Alive = false;
        return;
    }
    //здесь меняем картинки и радиус
    int radius[3] = { 75, 75, 36 };
    shape.setRadius(radius[level]);
    shape.setOrigin(radius[level], radius[level]);
    switch (level)
    {
    case 1: {
        Sprite AsterSprite(AsteroidTexture, IntRect(128, 38, 75, 75)); // коцаный
    }
    case 2: {
        Sprite AsterSprite(AsteroidTexture, IntRect(58, 155, 36, 36)); // предсмертный
    }
    };

    float angle = 90 % 360;
    direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));
}

void Asteroid::update() {
    if (!is_Alive) return;

    sf::Vector2f distance = direction * speed[level] * 60;
    move(distance);

    sf::Vector2f position = getPosition();
    int radius[3] = { 75, 75, 36 };
    //здесь 800 - высота окна
    if (position.y > (800 - radius[level])) {
        delete this;
    }
    setPosition(position);
}