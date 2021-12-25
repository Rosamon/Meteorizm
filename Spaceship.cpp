#include "Spaceship.h"



Spaceship::Spaceship() {
    image.loadFromFile("images\\Kursa4.png" );//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта.
    texture.loadFromImage(image);//закидываем наше изображение в текстуру
    sprite.setTexture(texture);//заливаем спрайт текстурой
    sprite.setTextureRect(IntRect(238, 38, 45, 73));  //Задаем спрайту один прямоугольник для вывода одного корабля. IntRect - приведение типов
    x = 500; y = 500;//координата появления спрайта
    live = 3;
    sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте
    speed = 1;
    reset();
    TouchBox.left = getPosition().x + 10;
    TouchBox.top = getPosition().y + 10;
    TouchBox.width = 35;
    TouchBox.height = 53;
}

Spaceship::~Spaceship() {
}
bool Spaceship::isСollision(sf::FloatRect rect) {

    // установка другой картинки на место коробля
    if (TouchBox.intersects(rect) || rect.intersects(TouchBox)) {
        if (rect.left + rect.width / 2 <= TouchBox.left)
        {
            setPosition(getPosition().x + 20, getPosition().y + 10);
            sprite.setPosition(sprite.getPosition().x + 20, sprite.getPosition().y + 10);
        }
        else
        {
            setPosition(getPosition().x - 20, getPosition().y - 10);
            sprite.setPosition(sprite.getPosition().x - 20, sprite.getPosition().y - 10);
        }
        live--;
        return true;
    }
    return false;
}

void Spaceship::reset() {
    setPosition(522.5, 530);
    rotate(-90);
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}
//void Spaceship::interactionWithMap() {
//    float   height = 1000, width = 1000;
//
//
    //if (x <= 0 || y <= 0 || x + 80 >= width || y + 80 >= height)

    //    // проверяем "направление скорости" ракеты:
    //{
    //    if (dy > 0)//если мы шли вниз,
    //    {
    //        y = height - 73;//то стопорим координату игрек персонажа. 
    //    }

    //    if (dx > 0)
    //    {
    //        x = width - 45;//если идем вправо
    //    }

    //    if (dy < 0)
    //    {
    //        y = +1;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх
    //    }

    //    if (dx < 0)
    //    {
    //        x = +1;//аналогично идем влево
    //    }
    //}
//}

void Spaceship::update(float frametime) {
    if (live == 2)
        textureBox = IntRect(235, 240, 45, 73);
    if (live == 1)
        textureBox = IntRect(39, 275, 45, 73);
    switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
    {
    case 0: dx = spee; dy = 0;   break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что ракета летит только вправо
    case 1: dx = -spee; dy = 0;   break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что ракета летит только влево
    case 2: dx = 0; dy = spee;   break;//по иксу задаем нулевое значение, по игреку положительное. получается, что ракета летит только вниз
    case 3: dx = 0; dy = -spee;   break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что ракета летит только вверх

    }

    //x = dx * frametime;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
    //y = dy * frametime;//аналогично по игреку
   /* interactionWithMap();*///вызываем функцию, отвечающую за взаимодействие с картой
    spee = 0; //зануляем скорость, чтобы ракета остановилась.
    
    if (dy != 0 ||dx != 0) {

        sf::Vector2f distance;
        distance.x = dx * frametime * speed;
        distance.y = dy * frametime * speed;

        move(distance);
        sprite.move(distance);
        TouchBox.left = getPosition().x + 10;
        TouchBox.top = getPosition().y + 10;
    }

    sf::Vector2f position = getPosition();
    if (position.x -55 < 0 || position.x + 60 > 1000 || position.y -55< 0 || position.y + 80 > 1000)
    {
       if (dx < 0)
           position.x = + 45;

     if (position.x + 70 > 1000)
        position.x = 1000 - 70;

    if (dy < 0)
        position.y = +55;

    if (position.y + 80 > 1000)
        position.y = 1000-80;
   
    setPosition(position);
    sf::Vector2f position2 = sprite.getPosition();
    if (x-45 <= 0 || y-35 <= 0 || x + 70 >= 1000 || y + 80 >= 1000)


            // проверяем "направление скорости" ракеты:
        {
            if (dy > 0)//если мы шли вниз,
            {
                position2.y = 1000 - 73;//то стопорим координату игрек персонажа. 
                sprite.setPosition(position2);
            }

            if (dx > 0)
            {
                position2.x = 1000 - 35;//если идем вправо
                sprite.setPosition(position2);
            }

            if (dy < 0)
            {
                position2.y = +1;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх
                sprite.setPosition(position2);
            }

            if (dx < 0)
            {
                position2.x = +20;//аналогично идем влево
                sprite.setPosition(position2);
            }
        }
    else  sprite.setPosition(position2);
    
    }
 

}
bool Spaceship::dedinside() {
    //Vector2f ghoul = sprite.getPosition();
    return(live == 0);
}
void Spaceship::onEvent(const sf::Event& event) {

        sprite.setTextureRect(IntRect(238, 38, 45, 73));
        Vector2f opa = getPosition();
        sprite.setPosition(opa.x - 23, opa.y - 35);
  
    if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {

        dir = 1; spee = 1;// направление влево
        sprite.setTextureRect(IntRect(319, 155, 68, 66));
        Vector2f opa = getPosition();
        sprite.setPosition(opa);
    }


    if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
        dir = 0; spee= 1;//направление вправо, см выше
        sprite.setTextureRect(IntRect(307, 45, 68, 66));
        Vector2f opa = getPosition();
        sprite.setPosition(opa.x-47,opa.y);
    }

    if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
        dir = 3; spee = 1;//направление вверх, см выше
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
        Vector2f opa = getPosition();
    /*    sprite.setPosition(opa.x - 23, opa.y - 35);*/
    }

    if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { 
        dir = 2; spee = 1;//направление вниз, см выше
        sprite.setTextureRect(IntRect(238, 38, 45, 73));
        Vector2f opa = getPosition();
  /*      if (opa.y <= 1000 - 90) {
            sprite.setPosition(opa.x + 23, opa.y + 35);
        }*/
    }

}

bool Spaceship::checkPoint(sf::Vector2f point) {
    
        float ax = sprite.getPosition().x ;
        float ay = sprite.getPosition().y;

        float px = point.x;
        float py = point.y;

        if ((px >= ax && px <= ax + 45 && py >= ay && py <= ay + 75)) {
            live--;
            return (true);
        }
        else
        {
            return(false);
        }
    
}



