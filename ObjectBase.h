#ifndef _OBJECTBASE_H_
#define _OBJECTBASE_H_
#include <SFML/Graphics.hpp>
// ������� ����� ��� ���������� � �����������
class ObjectBase  {
public:
    ObjectBase(); // �����������
    ~ObjectBase(); // ����������
    sf::FloatRect getTouchBox();// �������, ������������ ���������� �����-�������
    bool isAlive(); // �������� �� �������������
    int getLevel(); // ���������� ������� 
protected:
    int level; // ������� �������
    bool is_Alive; // ��������� �������
    sf::FloatRect TouchBox;// �����-������� ��� ��������� ������������ � �������
};
#endif
