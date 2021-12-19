#ifndef _SPACESHIP_HPP_
#define _SPACESHIP_HPP_

#include <math.h>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
using namespace sf;
class Spaceship: public sf::Drawable, public sf::Transformable {


    public:
        Spaceship();
        ~Spaceship();
       
        float x, y, w, h, dx, dy,speed, spee = 0; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
        int dir = 0; //����������� (direction) �������� ������
        Image image;//�����������
        Texture texture;// ��������
        Sprite sprite;// ������
        void reset();
        void update(float frametime);
        void interactionWithMap();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void onEvent(const sf::Event& event);
        sf::Vector2f position;


};
#endif
