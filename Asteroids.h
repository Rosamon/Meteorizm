#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_

#include <SFML/Graphics.hpp>
//#include "ObjectBase.h"

#ifndef DEG2RAD
#define DEG2RAD 3.14159f / 180.0f // перевод из градусов в радианы
#endif // !DEG2RAD

using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::


// интерфейс класса Asteroid
class Asteroid :  public sf::Drawable, public sf::Transformable {

public:
    Asteroid(); // наследуем конструктор базового класса
    Asteroid(int level); // конструктор с параметром "уровень"
    Asteroid(Vector2f position, float angle, int level); // конструктор с параметрами "позиция", "угол" - для направления, "уровень"
    ~Asteroid(); // деструктор 
    bool isAlive(); // проверка на существование
    int getLevel(); // возвращает уровень астероида
    bool checkPoint(Vector2f point); // проверка на касание границ окна игры
    void breakDown(); // функция-разрушение астероида
    void update(); // функция, обновляющая астероид в окне
    //////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    //////
private:
    int level; // уровень астероида
    bool is_Alive; // состояние астероида
    Vector2f direction; // направление астероида
    Sprite AsterSprite; // спрайт для астероида
    
};
#endif