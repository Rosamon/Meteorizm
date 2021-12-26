#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_

#include "ObjectBase.h"

#ifndef DEG2RAD
#define DEG2RAD 3.14159f / 180.0f // ������� �� �������� � �������
#endif // !DEG2RAD

using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::


// ��������� ������ Asteroid
class Asteroid : virtual public ObjectBase, public sf::Drawable, public sf::Transformable {

public:
    Asteroid(int level); // ����������� � ���������� "�������"
    ~Asteroid(); // ���������� 
    int getLevel(); // ���������� ������� ���������
    bool checkPoint(Vector2f point); // �������� �� ������� ������ ���� ����
    void breakDown(); // �������-���������� ���������
    void update(); // �������, ����������� �������� � ����
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::FloatRect getTouchBox();// �������, ������������ ���������� �����-������� 
private:
    int level; // ������� ���������
    Vector2f direction; // ����������� ���������
    Sprite AsterSprite; // ������ ��� ���������
    sf::FloatRect TouchBox;// �����-������� ��� ��������� ������������ � �������
    
};
#endif