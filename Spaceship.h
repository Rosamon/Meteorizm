#ifndef _SPACESHIP_HPP_
#define _SPACESHIP_HPP_


#include <SFML/Graphics.hpp>
#include "Constants.h"
using namespace sf;
class Spaceship: public sf::Drawable, public sf::Transformable {

    public:
        Spaceship();
        ~Spaceship();

  float x, y, w, h, dx, dy, speed = 0; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
        int dir = 0; //����������� (direction) �������� ������
        Image image;//�����������
        Texture texture;// ��������
        Sprite sprite;// ������

};
#endif
