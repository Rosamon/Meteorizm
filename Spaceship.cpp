#include "Spaceship.hpp"



Spaceship::Spaceship() {
    image.loadFromFile("images\\ship.png" );//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������.
    texture.loadFromImage(image);//���������� ���� ����������� � ��������
    sprite.setTexture(texture);//�������� ������ ���������
    x = 475; y = 915;//���������� ��������� �������
    sprite.setTextureRect(IntRect(238, 38, 45, 73));  //������ ������� ���� ������������� ��� ������ ������ �������. IntRect - ���������� �����
}

Spaceship::~Spaceship() {
}

void Spaceship::reset() {
    setPosition(475, 915);
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}
void Spaceship::interactionWithMap() {
    float   height = 1000, width = 1000;


    if (x < 0 || y < 0 || x + 68 > width || y + 75 > height)

        // ��������� "����������� ��������" ������:
    {
        if (dy > 0)//���� �� ��� ����,
        {
            y = y - 1;//�� �������� ���������� ����� ���������. 
        }

        if (dx > 0)
        {
            x = x - 1;//���� ���� ������
        }

        if (dy < 0)
        {
            y = +1;//���������� � ������� �����. dy<0, ������ �� ���� �����
        }

        if (dx < 0)
        {
            x = +1;//���������� ���� �����
        }
    }
}
void Spaceship::update(float time) {
    switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
    {
    case 0: dx = speed; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� ������ ����� ������ ������
    case 1: dx = -speed; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� ������ ����� ������ �����
    case 2: dx = 0; dy = speed;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� ������ ����� ������ ����
    case 3: dx = 0; dy = -speed;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� ������ ����� ������ �����

    }

    x += dx * time;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
    y += dy * time;//���������� �� ������
    interactionWithMap();//�������� �������, ���������� �� �������������� � ������
    speed = 0;//�������� ��������, ����� ������ ������������.
    sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����
}

void Spaceship::onEvent(const sf::Event& event) {
  
    if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {

        dir = 1; speed = 0.2;//dir =1 - ����������� �����, speed =0.1 - �������� ��������.
        sprite.setTextureRect(IntRect(319, 155, 68, 66));
    }


    if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
        dir = 0; speed = 0.2;//����������� ������, �� ����
        sprite.setTextureRect(IntRect(307, 45, 68, 66));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
        dir = 3; speed = 0.2;//����������� ����, �� ����
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
        dir = 2; speed = 0.2;//����������� �����, �� ����
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
    }

}
