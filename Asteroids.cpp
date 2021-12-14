#include "Asteroids.h"


 Asteroid::Asteroid(int level) : is_Alive(true), level(level) {
    int angle = 270 % 360; // угол в 270 градусов, задаем направление строго вниз
    direction = Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));

    int x = rand() % 400; // 400 - предполагаемая ширина окна
    int y = rand() % 100; // 100 - первые сто px сверху окна

    //скорости и размеры Астероида
    float speed[3] = { 0.03f, 0.05f, 0.07f };
    float radius[3] = { 40.0f, 20.0f, 10.0f };

    Vector2f position(x, y);
    setPosition(position);


    // Создаем переменную текстуры
    Texture texture;

    // Подгружаем нашу текстуру из файла texture.png
    texture.loadFromFile("../images/Kursa4.png");

    // Создаем спрайт и устанавливаем ему нашу текстуру
    shape.setTexture(&texture);
    shape.setTextureRect(IntRect(10, 10, 100, 100));
    shape.setOrigin(radius[level], radius[level]);
}


Asteroid::~Asteroid() {
}

bool Asteroid::isAlive() {
    return is_Alive;
}

void Asteroid::draw(RenderTarget& target, RenderStates states) const {
    states.transform *= getTransform();
    target.draw(shape, states);
}

int Asteroid::getLevel() {
    return level;
} 
