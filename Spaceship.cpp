#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
class SpaceShip { // класс »грока
public:
    float x, y, w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
    int dir = 0; //направление (direction) движени€ игрока
    String File; //файл с картинкой
    Image image;//изображение
    Texture texture;// текстура
    Sprite sprite;// спрайт

    SpaceShip(String F, float X, float Y, float W, float H) {  // онструктор с параметрами. ѕри создании объекта класса мы будем задавать им€ файла, координату ’ и ”, ширину и высоту
        File = F;//им€ файла
        w = W; h = H;//высота и ширина
        image.loadFromFile("images\\" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта.
        texture.loadFromImage(image);//закидываем наше изображение в текстуру
        sprite.setTexture(texture);//заливаем спрайт текстурой
        x = X; y = Y;//координата по€влени€ спрайта
        sprite.setTextureRect(IntRect(238, 38, w, h));  //«адаем спрайту один пр€моугольник дл€ вывода одного корабл€. IntRect - приведение типов
    }
};