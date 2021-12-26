#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_

#include "ObjectBase.h"

#ifndef DEG2RAD
#define DEG2RAD 3.14159f / 180.0f // перевод из градусов в радианы
#endif // !DEG2RAD

using namespace sf;//включаем пространство имен sf, чтобы посто€нно не писать sf::


// интерфейс класса Asteroid
class Asteroid : virtual public ObjectBase, public sf::Drawable, public sf::Transformable {

public:
    Asteroid(int level); // конструктор с параметром "уровень"
    ~Asteroid(); // деструктор 
    int getLevel(); // возвращает уровень астероида
    bool checkPoint(Vector2f point); // проверка на касание границ окна игры
    void breakDown(); // функци€-разрушение астероида
    void update(); // функци€, обновл€юща€ астероид в окне
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::FloatRect getTouchBox();// функци€, вовзращающа€ координаты формы-коробки 
private:
    int level; // уровень астероида
    Vector2f direction; // направление астероида
    Sprite AsterSprite; // спрайт дл€ астероида
    sf::FloatRect TouchBox;// форма-коробка дл€ обработки столкновени€ с ракетой
    
};
#endif