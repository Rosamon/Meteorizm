#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Enemy.h"
//#include "Bullet.h"
#include "Asteroid.h"
#include "Spaceship.h"//пока нет
#include <SFML/Graphics.h>

class Level {
    public:
        Level();
        ~Level();
        void onEvent(const sf::Event& event);
        void update(float frametime, int);
        void show(sf::RenderTarget& target);
        void start();

    private:
        Spaceship ship;
        std::vector<Bullet> bullets;
        std::vector<Asteroid> asteroids;
        Enemy* UFO;
};

#endif