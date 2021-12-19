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
    void update(float time) //������� "���������" ������� ������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
    {
        switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
        {
        case 0: dx = speed; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� ������ ����� ������ ������
        case 1: dx = -speed; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� ������ ����� ������ �����
        case 2: dx = 0; dy = speed;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� ������ ����� ������ ����
        case 3: dx = 0; dy = -speed;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� ������ ����� ������ �����

        }

        x += dx * time;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
        y += dy * time;//���������� �� ������
        interactionWithMap();//�������� �������, ���������� �� �������������� � ������
        speed = 0;//�������� ��������, ����� ������ ������������.
        sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����

    }
    void interactionWithMap()//�-��� �������������� � ������
    {
        float   height = 800, width = 400;


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
    //float getShipCoordX() {
  //    return x;
  //}
  //float getShipCoordY() {
  //    return y;
  //}


};
int main()
{
    RenderWindow window(VideoMode(400, 800), "ship");


    SpaceShip first("Kursa4.png", 175, 720, 45, 73);


    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {

            first.dir = 1; first.speed = 0.2;//dir =1 - ����������� �����, speed =0.1 - �������� ��������.
            first.sprite.setTextureRect(IntRect(319, 155, 68, 66));
        }
        //if ((Keyboard::isKeyPressed(Keyboard::A) && (Keyboard::isKeyPressed(Keyboard::W)))) {

        //    first.dir = 4; first.speed = 0.1;//dir =1 - ����������� �����, speed =0.1 - �������� ��������. 
        //    first.sprite.setTextureRect(IntRect(319, 155, 68, 66));
        //}
        //if ((Keyboard::isKeyPressed(Keyboard::D) && (Keyboard::isKeyPressed(Keyboard::W)))) {
        //    first.dir = 5; first.speed = 0.1;//����������� ������, �� ����
        //    first.sprite.setTextureRect(IntRect(307, 45, 68, 66));
        //}

        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            first.dir = 0; first.speed = 0.2;//����������� ������, �� ����
            first.sprite.setTextureRect(IntRect(307, 45, 68, 66));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            first.dir = 3; first.speed = 0.2;//����������� ����, �� ����
            first.sprite.setTextureRect(IntRect(238, 38, 45, 73));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
            first.dir = 2; first.speed = 0.2;//����������� �����, �� ����
            first.sprite.setTextureRect(IntRect(238, 38, 45, 73));
        }

        first.update(time);
        window.clear();
        window.draw(first.sprite);
        window.display();


    }
    return 0;
}
};