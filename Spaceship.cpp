#include <iostream>
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

    SpaceShip(String F, float X, float Y, float W, float H) {  //Конструктор с параметрами. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
        File = F;//имя файла
        w = W; h = H;//высота и ширина
        image.loadFromFile("images\\" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта.
        texture.loadFromImage(image);//закидываем наше изображение в текстуру
        sprite.setTexture(texture);//заливаем спрайт текстурой
        x = X; y = Y;//координата появления спрайта
        sprite.setTextureRect(IntRect(238, 38, w, h));  //Задаем спрайту один прямоугольник для вывода одного корабля. IntRect - приведение типов
    }
    void update(float time) //функция "оживления" объекта класса. Принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
    {
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
    void interactionWithMap()//ф-ция взаимодействия с картой
    {
        float   height = 800, width = 400;


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


    SpaceShip first("ship.png", 175, 720, 45, 73);


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

            first.dir = 1; first.speed = 0.2;//dir =1 - направление вверх, speed =0.1 - скорость движения.
            first.sprite.setTextureRect(IntRect(319, 155, 68, 66));
        }
        //if ((Keyboard::isKeyPressed(Keyboard::A) && (Keyboard::isKeyPressed(Keyboard::W)))) {

        //    first.dir = 4; first.speed = 0.1;//dir =1 - направление вверх, speed =0.1 - скорость движения. 
        //    first.sprite.setTextureRect(IntRect(319, 155, 68, 66));
        //}
        //if ((Keyboard::isKeyPressed(Keyboard::D) && (Keyboard::isKeyPressed(Keyboard::W)))) {
        //    first.dir = 5; first.speed = 0.1;//направление вправо, см выше
        //    first.sprite.setTextureRect(IntRect(307, 45, 68, 66));
        //}

        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            first.dir = 0; first.speed = 0.2;//направление вправо, см выше
            first.sprite.setTextureRect(IntRect(307, 45, 68, 66));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            first.dir = 3; first.speed = 0.2;//направление вниз, см выше
            first.sprite.setTextureRect(IntRect(238, 38, 45, 73));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
            first.dir = 2; first.speed = 0.2;//направление вверх, см выше
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