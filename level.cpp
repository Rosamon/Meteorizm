#include "Level.h"

Level::Level() {
    for (int i=0; i < 3; i++) {
        Asteroid a(0);
        asteroids.push_back(a);
    }
}

Level::~Level() {
}

void Level::onEvent(const sf::Event& event) {
    ship.onEvent(event);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        Bullet bullet(ship.getPosition(), ship.getRotation());
        bullets.push_back(bullet);
    }
}
void Level::update(float frametime, int my_timer) {
    ship.update(frametime);
    if (UFO != nullptr)
    {
        UFO->update(frametime);
    }
    /////////////////
    if ((my_timer % 300) == 0 && UFO != nullptr && UFO->isAlive())///////////////
    {
        bullets.push_back(UFO->aim(ship.getPosition()));/////////////
       
    }
    if ((my_timer % 3000 == 0) && UFO == nullptr)
    {
        UFO = new Enemy(2);  
    }
    if (UFO != nullptr && !UFO->isAlive())
    {
        delete UFO;
        UFO = nullptr;
    }
    //Работа класса enemy
    ////////////////
    std::vector<Bullet>::iterator start_bullets = bullets.begin();
    while (start_bullets != bullets.end()) {
        if (start_bullets->isAlive()) {
            start_bullets->update(frametime);
            ++start_bullets;
        } else
            start_bullets = bullets.erase(start_bullets);
    }

    std::vector<Asteroid>::iterator start_asteroids = asteroids.begin();
    while (start_asteroids != asteroids.end()) {
        if (start_asteroids->isAlive()) {
            start_asteroids->update(frametime);
            ++start_asteroids;
        } else
            start_asteroids = asteroids.erase(start_asteroids);
    }

    std::vector<Asteroid> new_asteroids;
    start_asteroids = asteroids.begin();

    while (start_asteroids != asteroids.end()) {
        start_bullets = bullets.begin();
        while (start_bullets != bullets.end()) {
            if (!start_bullets->isAlive()) {
                ++start_bullets;
                continue;
            }

            if (start_asteroids->checkPoint(start_bullets->getPosition())){
                start_bullets->kill();
                start_asteroids->breakDown();

                if (start_asteroids->isAlive()) {
                    sf::Vector2f position = start_asteroids->getPosition();
                    float angle = rand() % 360;
                    Asteroid a(position, angle, start_asteroids->getLevel());
                    new_asteroids.push_back(a);
                }
                break;
                ////
                if (UFO != nullptr && !start_bullets->isItEnemy() && UFO->checkPoint(start_bullets->getPosition()))///////////////
                {
                    UFO->punch(true);
                    start_bullets->kill();
                }
                // Взаимодействие с тарелкой
                ////////////////
            }
            ++start_bullets;
        }
        ++start_asteroids;
    }
    asteroids.insert(asteroids.end(), new_asteroids.begin(), new_asteroids.end());
}

void Level::show(sf::RenderTarget& target) {
    target.draw(ship);

    //
    if (UFO != nullptr && UFO->isAlive())
    {
        sf::RenderStates states;
           UFO->draw(target, states);
    }
    // Отрисовка тарелки
    ///////////
    for(std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it)
        target.draw(*it);

    for(std::vector<Asteroid>::iterator it = asteroids.begin(); it != asteroids.end(); ++it)
        target.draw(*it);
}

void Level::start() {
}
