#include "Spaceship.hpp"



Spaceship::Spaceship() {
    image.loadFromFile("images\\ship.png" );//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта.
    texture.loadFromImage(image);//закидываем наше изображение в текстуру
    sprite.setTexture(texture);//заливаем спрайт текстурой
    x = 475; y = 915;//координата появления спрайта
    sprite.setTextureRect(IntRect(238, 38, 45, 73));  //Задаем спрайту один прямоугольник для вывода одного корабля. IntRect - приведение типов
}

Spaceship::~Spaceship() {
}

void Spaceship::reset() {
    setPosition(475, 915);
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}
void Spaceship::interactionWithMap() {
    float   height = 1000, width = 1000;


    if (x < 0 || y < 0 || x + 68 > width || y + 75 > height)

        // проверяем "направление скорости" ракеты:
    {
        if (dy > 0)//если мы шли вниз,
        {
            y = y - 1;//то стопорим координату игрек персонажа. 
        }

        if (dx > 0)
        {
            x = x - 1;//если идем вправо
        }

        if (dy < 0)
        {
            y = +1;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх
        }

        if (dx < 0)
        {
            x = +1;//аналогично идем влево
        }
    }
}
