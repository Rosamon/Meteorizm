#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_


#include <SFML/Graphics.hpp>
using namespace sf;
class SpaceShip { // класс Игрока 
public:
    float x, y, w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
    int dir = 0; //направление (direction) движения игрока
    String File; //файл с картинкой
    Image image;//изображение
    Texture texture;// текстура
    Sprite sprite;// спрайт
    SpaceShip(String F, float X, float Y, float W, float H);

};
#endif
