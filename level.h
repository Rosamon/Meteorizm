#ifndef _LEVEL_H_ //Если не объявлен level.h, то объявить его.
#define _LEVEL_H_

#include "Enemy.h" // Подключаем библиотеки
//#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include "Asteroids.h"
#include "Spaceship.h"//пока нет


class Level { // Объявляем класс
    public: // Методы
        Level();//Конструктор
        ~Level();//Деструктор
        void onEvent(const sf::Event& event);//Обработка событий
        bool update(float frametime);//Обновление картинок
        void show(sf::RenderTarget& target);//Показ объекта
        void start();

    private://Поля(атрибуты)
        Spaceship ship;//Корабль типа класса spaceship
        std::vector<Bullet> bullets;//Вектор(список) пуль
        std::vector<Asteroid> asteroids;//Вектор(список) астероидов
        Enemy* UFO;//НЛО добавил Рома
        float ShipTimer, UFOAimTimer, UFOSpawnTimer, AsteroidSpawnTimer = 0;//Таймеры
        Font font;//Фон
        Text text;//Текст
        int Score;//Очки игрока

};

#endif