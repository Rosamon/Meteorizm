#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_


#include <SFML/Graphics.hpp>
using namespace sf;
class SpaceShip { // ����� ������ 
public:
    float x, y, w, h, dx, dy, speed = 0; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
    int dir = 0; //����������� (direction) �������� ������
    String File; //���� � ���������
    Image image;//�����������
    Texture texture;// ��������
    Sprite sprite;// ������
    SpaceShip(String F, float X, float Y, float W, float H);

};
#endif
