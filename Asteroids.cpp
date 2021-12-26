#include "Asteroids.h"
Texture AsteroidTexture; // текстура для астероида

Asteroid::Asteroid(int level) : level(level) {
     //скорости и размеры Астероида
     float speed[3] = { 0.03f, 0.05f, 0.07f };
     int radius[3] = { 37.5, 37.5, 18};

     is_Alive = true;

     //работа с изображением
     Image AsterImage;
     AsterImage.loadFromFile("images/Kursa4.png");
     AsteroidTexture.loadFromImage(AsterImage);
     AsterSprite = Sprite(AsteroidTexture, IntRect(38, 38, 75, 75)); // целый
     AsterSprite.setOrigin(radius[level], radius[level]);

     direction = sf::Vector2f(0, 1);

    int x = radius[level] + rand() % (1000 - radius[level]); // 1000 - предполагаемая ширина окна
    int y = radius[level] + rand() % 100; // 100 - первые сто px сверху окна

    Vector2f position(x, y);
    setPosition(position.x - radius[level], position.y - radius[level]);
    AsterSprite.setPosition(position);
    
    TouchBox.left = getPosition().x ;
    TouchBox.top = getPosition().y ;
    TouchBox.width = 60;
    TouchBox.height = 60;
}


Asteroid::~Asteroid() {
}



bool Asteroid::checkPoint(sf::Vector2f point) {
    float ax = getPosition().x;
    float ay = getPosition().y;

    float px = point.x + 5;
    float py = point.y + 5;

    int radius[3] = { 37.5, 37.5, 18 };
    float sqrDistance = ((ax - px) * (ax - px)) + ((ay - py) * (ay - py));
    float sqrRadius = radius[level] * radius[level];

    return (sqrDistance <= sqrRadius);
}


int Asteroid::getLevel() {
    return level;
}

sf::FloatRect Asteroid::getTouchBox() {
    return TouchBox;
}
void Asteroid::breakDown() {
    level++;

    if (level > 2) {
        is_Alive = false;
        return;
    }
    //здесь меняем картинки, размер формы-коробки и радиус
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

        TouchBox.left = getPosition().x;
        TouchBox.top = getPosition().y;
        TouchBox.height = 35;
        TouchBox.width = 35;
        
        break;
    }
    };
    
}

void Asteroid::update() {
    if (!is_Alive) return;

    AsterSprite.rotate(0.5);

    float speed[3] = { 0.03f, 0.05f, 0.07f };
    sf::Vector2f distance = direction * speed[level] * 20.0f;
    move(distance);
    AsterSprite.move(distance);
    sf::Vector2f position = getPosition();

    int radius[3] = { 37.5, 37.5, 18 };
    //здесь 1000 - высота окна
    if (position.y > (1000 - radius[level])) {
        is_Alive = false;
    }
    setPosition(position);
    AsterSprite.setPosition(position);
   
    TouchBox.left = getPosition().x;//
    TouchBox.top = getPosition().y;//
    
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // проверяем на ложное срабатывание
    if (AsterSprite.getPosition().x != 0) {
        target.draw(AsterSprite);
    }
   
}