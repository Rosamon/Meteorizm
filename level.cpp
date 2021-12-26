#include "Level.h"
#include <sstream>
Level::Level() {
    font.loadFromFile("images\\CyrilicOld.ttf");
    text.setFont(font);
    //text.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(20,20);

    Score = 0;

    for (int i=0; i < 3; i++) {
        Asteroid a(0);///
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
    
    ShipTimer += frametime;//
    UFOAimTimer += frametime;//
    UFOSpawnTimer += frametime;//
    AsteroidSpawnTimer += frametime;//

    if (ShipTimer > 300)///////////////
    {
        Bullet bullet(ship.getPosition(), ship.getRotation(), false);
        bullets.push_back(bullet);
        ShipTimer = 0;
    }
    if (UFO != nullptr)
    {
        UFO->update(frametime);
        if (ship.isСollision(UFO->getTouchBox())) {//Столкновение
            UFO->punch(true);//
            Score++;
        }
    }
    /////////////////


    if (UFOAimTimer > 500 && UFO != nullptr && UFO->isAlive())
    {
        bullets.push_back(UFO->aim(ship.getPosition()));

        UFOAimTimer = 0;
    }
    if ((UFOSpawnTimer > 30000) && UFO == nullptr)
    {
        UFO = new Enemy((rand() % 3 + 1));  
        UFOSpawnTimer = 0;
    }
    if (UFO != nullptr && !UFO->isAlive())
    {
        Score += 5;
        delete UFO;
        UFO = nullptr;
    }
    if (AsteroidSpawnTimer > 1500)///////////////
    {
        Asteroid a(0);///
        asteroids.push_back(a);
        AsteroidSpawnTimer = 0;
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
            if (ship.isСollision(start_asteroids->getTouchBox())) {//Столкновение
                start_asteroids->breakDown();//
                Score++;
            }
            start_asteroids->update();
            ++start_asteroids;
        } else
            start_asteroids = asteroids.erase(start_asteroids);
    }

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
                if(!start_bullets->isItEnemy())
                Score++;
                break;
                ////
            }
            ++start_bullets;
        }
        ++start_asteroids;
    }
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
        if (UFO != nullptr && UFO->checkPoint(start_bullets->getPosition()))//1
        {
            UFO->punch(true);
            start_bullets->kill();
        }
        // Взаимодействие с тарелкой
        ////////////////     
        ++start_bullets;
        }
    if (ship.dedinside())
        return false;
    
    //asteroids.insert(asteroids.end(), new_asteroids.begin(), new_asteroids.end());
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
    
    std::ostringstream playerScoreString;    // объявили переменную
    playerScoreString << Score;
    text.setString("Score: " + playerScoreString.str());
    target.draw(text);
    
}

void Level::start() {
}
