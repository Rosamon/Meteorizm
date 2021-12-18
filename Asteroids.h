#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_

#include <SFML/Graphics.hpp>
#include "ObjectBase.h"


#define DEG2RAD 3.14159f / 180.0f // ������� �� �������� � �������

using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::


// ��������� ������ Asteroid
class Asteroid : public ObjectBase, public sf::Drawable, public sf::Transformable {

public:
    Asteroid() : ObjectBase() {}; // ��������� ����������� �������� ������
    Asteroid(int level); // ����������� � ���������� "�������"
    Asteroid(Vector2f position, float angle, int level); // ����������� � ����������� "�������", "����" - ��� �����������, "�������"
    ~Asteroid(); // ���������� 
    bool isAlive(); // �������� �� �������������
    int getLevel(); // ���������� ������� ���������
    bool checkPoint(Vector2f point); // �������� �� ������� ������ ���� ����
    void breakDown(); // �������-���������� ���������
    void update(); // �������, ����������� �������� � ����

private:
    int level; // ������� ���������
    bool is_Alive; // ��������� ���������
    Vector2f direction; // ����������� ���������
    Sprite AsterSprite; // ������ ��� ���������
    Texture AsteroidTexture; // �������� ��� ���������
};
#endif