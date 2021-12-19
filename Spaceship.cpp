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
