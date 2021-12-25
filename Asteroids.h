#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_

#include <SFML/Graphics.hpp>
//#include "ObjectBase.h"

#ifndef DEG2RAD
#define DEG2RAD 3.14159f / 180.0f // ������� �� �������� � �������
#endif // !DEG2RAD

using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::


// ��������� ������ Asteroid
class Asteroid :  public sf::Drawable, public sf::Transformable {

public:
    Asteroid(); // ��������� ����������� �������� ������
    Asteroid(int level); // ����������� � ���������� "�������"
    Asteroid(Vector2f position, float angle, int level); // ����������� � ����������� "�������", "����" - ��� �����������, "�������"
    ~Asteroid(); // ���������� 
    bool isAlive(); // �������� �� �������������
    int getLevel(); // ���������� ������� ���������
    bool checkPoint(Vector2f point); // �������� �� ������� ������ ���� ����
    void breakDown(); // �������-���������� ���������
    void update(); // �������, ����������� �������� � ����
    //////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    //////
    sf::FloatRect getTouchBox();// �������, ������������ ���������� �����-������� 
private:
    int level; // ������� ���������
    bool is_Alive; // ��������� ���������
    Vector2f direction; // ����������� ���������
    Sprite AsterSprite; // ������ ��� ���������
    sf::FloatRect TouchBox;// �����-������� ��� ��������� ������������ � �������
    
};
#endif