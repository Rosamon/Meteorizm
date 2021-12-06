#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_


// ��������� ������ Asteroid
class Asteroid{

public:
    Asteroid(int level);
    ~Asteroid();

    int getLvl(); // �������� �������� ������
    bool isAlive(); // �������� ��������� ���������
    void breakDown(); // �������� ��� ��������� � ��������

private:
    int lvl; // �������� ������ 
    bool isAlive; // ��������� ���������
};
#endif