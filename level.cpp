#include "Level.h"
#include <sstream>
Level::Level() {
    font.loadFromFile("images\\CyrilicOld.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(20,20);

    Score = 0;

    for (int i=0; i < 3; i++) {
        Asteroid a(0);
        asteroids.push_back(a);
    }
}

Level::~Level() {
}

void Level::onEvent(const sf::Event& event) {
    ship.onEvent(event);
}

bool Level::update(float frametime) {
    ship.update(frametime);
    
    ShipTimer += frametime;
    UFOAimTimer += frametime;
    UFOSpawnTimer += frametime;
    AsteroidSpawnTimer += frametime;
    //до сюда обновление таймеров
    if (ShipTimer > 300)
    {
        Bullet bullet(ship.getPosition(), ship.getRotation(), false);
        bullets.push_back(bullet);
        ShipTimer = 0;
    }
    //Работа класса Spaceship до сюда
    if (UFO != nullptr)
    {
        UFO->update(frametime);
        if (ship.isСollision(UFO->getTouchBox())) {//Столкновение
            UFO->punch(true);//
            Score++;
        }
    }
    if (UFOAimTimer > 500 && UFO != nullptr && UFO->isAlive())
    {
        bullets.push_back(UFO->aim(ship.getPosition()));

        UFOAimTimer = 0;
    }
    if ((UFOSpawnTimer > 20000) && UFO == nullptr)
    {
        UFO = new Enemy((rand() % 3 + 1));  
        UFOSpawnTimer = 0;
    }
    if (UFO != nullptr && !UFO->isAlive())
    {
        Score += 5;
        UFOSpawnTimer = 0;
        delete UFO;
        UFO = nullptr;
    }
    //Работа класса enemy до сюда
    if (AsteroidSpawnTimer > 1500)
    {
        Asteroid a(0);///
        asteroids.push_back(a);
        AsteroidSpawnTimer = 0;
    }
    
    
    std::vector<Bullet>::iterator start_bullets = bullets.begin();
    while (start_bullets != bullets.end()) {
        if (start_bullets->isAlive()) {
            start_bullets->update(frametime);
            ++start_bullets;
        } else
            start_bullets = bullets.erase(start_bullets);
    }
    //выше движение пуль и их удаление
    std::vector<Asteroid>::iterator start_asteroids = asteroids.begin();
    while (start_asteroids != asteroids.end()) {
        if (start_asteroids->isAlive()) {
            if (ship.isСollision(start_asteroids->getTouchBox())) {//Столкновение
                start_asteroids->breakDown();
                Score++;
            }
            start_asteroids->update();
            ++start_asteroids;
        } else
            start_asteroids = asteroids.erase(start_asteroids);
    }
    //выше проверка на столкновение коробля с астероидами
    start_asteroids = asteroids.begin();
    while (start_asteroids != asteroids.end()) {
        start_bullets = bullets.begin();
        while (start_bullets != bullets.end()) {
            if (!start_bullets->isAlive()) {
                ++start_bullets;
                continue;//если пуля стерта, то пропустить ее
            }
            if (start_asteroids->checkPoint(start_bullets->getPosition())){
                start_bullets->kill();
                start_asteroids->breakDown();
                if(!start_bullets->isItEnemy())
                Score++;
                break;
            }
            ++start_bullets;
        }
        ++start_asteroids;
    }
    //выше проверка пересечений пуль и астероидов
    start_bullets = bullets.begin();
    while (start_bullets != bullets.end()) {
        if (!start_bullets->isAlive() || start_bullets->isItEnemy()) {
            if (ship.checkPoint(start_bullets->getPosition()))
            {
                start_bullets->kill(); 
            }
            ++start_bullets;
            continue;
        }
        //проверка на принодлежность пуль к врагу и на их пересечение с коаблем
        if (UFO != nullptr && UFO->checkPoint(start_bullets->getPosition()))
        {
            UFO->punch(true);
            start_bullets->kill();
        }
        // Взаимодействие с тарелкой    
        ++start_bullets;
        }
    if (ship.life())
        return false;
    
    return true;
}

void Level::show(sf::RenderTarget& target) {
    
    for(std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it)
        target.draw(*it);

    target.draw(ship);

    for(std::vector<Asteroid>::iterator it = asteroids.begin(); it != asteroids.end(); ++it)
        target.draw(*it);

    if (UFO != nullptr && UFO->isAlive())
    {
        sf::RenderStates states;
        UFO->draw(target, states);
    }
    
    std::ostringstream playerScoreString; // объявили переменную
    playerScoreString << Score;
    text.setString("Score: " + playerScoreString.str());
    target.draw(text);
    
}

void Level::start() {
}
