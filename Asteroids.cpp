#include "Asteroids.h"


 Asteroid::Asteroid(int level) : is_Alive(true), level(level) {
    int angle = 270 % 360; // ���� � 270 ��������, ������ ����������� ������ ����
    direction = Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));

    int x = rand() % 400; // 400 - �������������� ������ ����
    int y = rand() % 100; // 100 - ������ ��� px ������ ����

    //�������� � ������� ���������
    float speed[3] = { 0.03f, 0.05f, 0.07f };
    float radius[3] = { 40.0f, 20.0f, 10.0f };

    Vector2f position(x, y);
    setPosition(position);


    // ������� ���������� ��������
    Texture texture;

    // ���������� ���� �������� �� ����� texture.png
    texture.loadFromFile("../images/Kursa4.png");

    // ������� ������ � ������������� ��� ���� ��������
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
