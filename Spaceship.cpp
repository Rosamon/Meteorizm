#include "Spaceship.h"



Spaceship::Spaceship() {
    image.loadFromFile("images\\ship.png" );//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта.
    texture.loadFromImage(image);//закидываем наше изображение в текстуру
    sprite.setTexture(texture);//заливаем спрайт текстурой
    sprite.setTextureRect(IntRect(238, 38, 45, 73));  //Задаем спрайту один прямоугольник для вывода одного корабля. IntRect - приведение типов
    x = 475; y = 915;//координата появления спрайта
    speed = 1;
    reset();
}

Spaceship::~Spaceship() {
}

void Spaceship::reset() {
    setPosition(475, 915);
    rotate(-90);
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
            y += 1;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх
        }

        if (dx < 0)
        {
            x += 1;//аналогично идем влево
        }
    }
}

void Spaceship::update(float frametime) {
    switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
    {
    case 0: dx = spee; dy = 0;   break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что ракета летит только вправо
    case 1: dx = -spee; dy = 0;   break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что ракета летит только влево
    case 2: dx = 0; dy = spee;   break;//по иксу задаем нулевое значение, по игреку положительное. получается, что ракета летит только вниз
    case 3: dx = 0; dy = -spee;   break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что ракета летит только вверх

    }

    x == dx * frametime;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
    y == dy * frametime;//аналогично по игреку
    interactionWithMap();//вызываем функцию, отвечающую за взаимодействие с картой
    spee = 0; //зануляем скорость, чтобы ракета остановилась.
    sprite.move(x,y);
    move(x,y);
    //sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте
    //if (dy != 0 ||dx != 0) {
//
     //   sf::Vector2f distance;
     //   distance.x += dx * frametime * speed;
     //   distance.y += dy * frametime * speed;
//
     //   move(distance);
     //   sprite.move(distance);
    //}
    spee = 0;
    sf::Vector2f position = getPosition();
    if (position.x < -10.0f)
        position.x = 0;
    else if (position.x > 1000)
        position.x = 1000.0f;

    if (position.y < -10.0f)
        position.y = 0;
    else if (position.y > 1000)
        position.y = 1000.0f;

    setPosition(position);
}

void Spaceship::onEvent(const sf::Event& event) {
  
    if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {

        dir = 1; spee = 0.2f;//dir =1 - направление вверх, speed =0.1 - скорость движения.
        sprite.setTextureRect(IntRect(319, 155, 68, 66));
    }


    if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
        dir = 0; spee= 0.2f;//направление вправо, см выше
        sprite.setTextureRect(IntRect(307, 45, 68, 66));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
        dir = 3; spee = 0.2f;//направление вниз, см выше
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
        dir = 2; spee = 0.2f;//направление вверх, см выше
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
    }

}
