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
void Spaceship::update(float time) {
    switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
    {
    case 0: dx = speed; dy = 0;   break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что ракета летит только вправо
    case 1: dx = -speed; dy = 0;   break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что ракета летит только влево
    case 2: dx = 0; dy = speed;   break;//по иксу задаем нулевое значение, по игреку положительное. получается, что ракета летит только вниз
    case 3: dx = 0; dy = -speed;   break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что ракета летит только вверх

    }

    x += dx * time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
    y += dy * time;//аналогично по игреку
    interactionWithMap();//вызываем функцию, отвечающую за взаимодействие с картой
    speed = 0;//зануляем скорость, чтобы ракета остановилась.
    sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте
}

void Spaceship::onEvent(const sf::Event& event) {
  
    if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {

        dir = 1; speed = 0.2;//dir =1 - направление вверх, speed =0.1 - скорость движения.
        sprite.setTextureRect(IntRect(319, 155, 68, 66));
    }


    if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
        dir = 0; speed = 0.2;//направление вправо, см выше
        sprite.setTextureRect(IntRect(307, 45, 68, 66));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
        dir = 3; speed = 0.2;//направление вниз, см выше
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
        dir = 2; speed = 0.2;//направление вверх, см выше
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
    }

}
