#include "Spaceship.h"



Spaceship::Spaceship() {
    image.loadFromFile("images\\Kursa4.png" );//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������.
    texture.loadFromImage(image);//���������� ���� ����������� � ��������
    sprite.setTexture(texture);//�������� ������ ���������
    sprite.setTextureRect(IntRect(238, 38, 45, 73));  //������ ������� ���� ������������� ��� ������ ������ �������. IntRect - ���������� �����
    x = 475; y = 915;//���������� ��������� �������
    speed = 1;
    reset();
}

Spaceship::~Spaceship() {
}

void Spaceship::reset() {
    setPosition(475, 915);
    rotate(-90);
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
            y += 1;//���������� � ������� �����. dy<0, ������ �� ���� �����
        }

        if (dx < 0)
        {
            x += 1;//���������� ���� �����
        }
    }
}

void Spaceship::update(float frametime) {
    switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
    {
    case 0: dx = spee; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� ������ ����� ������ ������
    case 1: dx = -spee; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� ������ ����� ������ �����
    case 2: dx = 0; dy = spee;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� ������ ����� ������ ����
    case 3: dx = 0; dy = -spee;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� ������ ����� ������ �����

    }

    x == dx * frametime;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
    y == dy * frametime;//���������� �� ������
    interactionWithMap();//�������� �������, ���������� �� �������������� � ������
    spee = 0; //�������� ��������, ����� ������ ������������.
    sprite.move(x,y);
    move(x,y);
    //sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����
    //if (dy != 0 ||dx != 0) {
//
     //   sf::Vector2f distance;
     //   distance.x += dx * frametime * speed;
     //   distance.y += dy * frametime * speed;
//
     //   move(distance);
     //   sprite.move(distance);
    //}
    spee = 0;
    sf::Vector2f position = getPosition();
    if (position.x < -10.0f)
        position.x = 0;
    else if (position.x > 1000)
        position.x = 1000.0f;

    if (position.y < -10.0f)
        position.y = 0;
    else if (position.y > 1000)
        position.y = 1000.0f;

    setPosition(position);
}

void Spaceship::onEvent(const sf::Event& event) {
  
    if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {

        dir = 1; spee = 0.2f;//dir =1 - ����������� �����, speed =0.1 - �������� ��������.
        sprite.setTextureRect(IntRect(319, 155, 68, 66));
    }


    if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
        dir = 0; spee= 0.2f;//����������� ������, �� ����
        sprite.setTextureRect(IntRect(307, 45, 68, 66));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
        dir = 3; spee = 0.2f;//����������� ����, �� ����
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
        dir = 2; spee = 0.2f;//����������� �����, �� ����
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
    }

}
