#ifndef _OBJECTBASE_H_
#define _OBJECTBASE_H_

// Базовый класс для Астероидов и Инопланетян
class ObjectBase  {
public:
    ObjectBase(); // конструктор
    ~ObjectBase(); // деструктор

protected:
    int level; // уровень объекта
    bool is_Alive; // состояние объекта
    bool isAlive(); // проверка на существование
    int getLevel(); // возвращает уровень 
};
#endif
