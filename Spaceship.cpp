#include <iostream>
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

    SpaceShip(String F, float X, float Y, float W, float H) {  //����������� � �����������. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
        File = F;//��� �����
        w = W; h = H;//������ � ������
        image.loadFromFile("images\\" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������.
        texture.loadFromImage(image);//���������� ���� ����������� � ��������
        sprite.setTexture(texture);//�������� ������ ���������
        x = X; y = Y;//���������� ��������� �������
        sprite.setTextureRect(IntRect(238, 38, w, h));  //������ ������� ���� ������������� ��� ������ ������ �������. IntRect - ���������� �����
    }
};