#ifndef _OBJECTBASE_H_
#define _OBJECTBASE_H_
#include <SFML/Graphics.hpp>
// Базовый класс для Астероидов и Инопланетян
class ObjectBase  {
public:
    ObjectBase(); // конструктор
    ~ObjectBase(); // деструктор
    sf::FloatRect getTouchBox();// функция, вовзращающая координаты формы-коробки
    bool isAlive(); // проверка на существование
    int getLevel(); // возвращает уровень 
protected:
    int level; // уровень объекта
    bool is_Alive; // состояние объекта
    sf::FloatRect TouchBox;// форма-коробка для обработки столкновения с ракетой
};
#endif
