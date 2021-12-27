#include "Level.h"
#include <sstream>
Level::Level() {
    font.loadFromFile("images\\CyrilicOld.ttf");// загружаем шрифт
    text.setFont(font);// ставим шрифт
    //text.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
    text.setCharacterSize(24); //размер шрифта
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);//стиль текста
    text.setPosition(20,20);//позиция текста

    Score = 0;//обнуляем счет

    for (int i=0; i < 3; i++) {//Создание 3 астероидов
        Asteroid a(0);//
        asteroids.push_back(a);//записываем его в вектор
    }
}

Level::~Level() {
}

void Level::onEvent(const sf::Event& event) {//Обработка событий корабля
    ship.onEvent(event);

    
}
bool Level::update(float frametime) {//Обновление картинок
    ship.update(frametime);
    
    ShipTimer += frametime;//
    UFOAimTimer += frametime;//
    UFOSpawnTimer += frametime;//
    AsteroidSpawnTimer += frametime;//

    if (ShipTimer > 300)//добавление пули в вектор
    {
        Bullet bullet(ship.getPosition(), ship.getRotation(), false);
        bullets.push_back(bullet);
        ShipTimer = 0;
    }
    if (UFO != nullptr)//Рома писал
    {
        UFO->update(frametime);
    }
    /////////////////

    //-----------------Рома
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
    //-------------------------Конец Роме!
    if (AsteroidSpawnTimer > 1500)//Генерация астероидов
    {
        Asteroid a(0);///
        asteroids.push_back(a);
        AsteroidSpawnTimer = 0;
    }
    //Работа класса enemy
    std::vector<Bullet>::iterator start_bullets = bullets.begin();//Обновление пули, переход к следующей
    while (start_bullets != bullets.end()) {
        if (start_bullets->isAlive()) {
            start_bullets->update(frametime);
            ++start_bullets;//переход к следующей пули 
        } else
            start_bullets = bullets.erase(start_bullets);//удаление пули с экрана
    }

    std::vector<Asteroid>::iterator start_asteroids = asteroids.begin();//Обновление астероида, переход к следующему
    while (start_asteroids != asteroids.end()) {
        if (start_asteroids->isAlive()) {
            if (ship.isСollision(start_asteroids->getTouchBox())) {//Столкновение
                start_asteroids->breakDown();//разрушение астероида
                Score++;//добавление очков 
            }
            start_asteroids->update();//если астероид живой, то обновляем
            ++start_asteroids;//переход к следующему астероиду
        } else
            start_asteroids = asteroids.erase(start_asteroids);//удаление астероида с экрана
    }

    start_asteroids = asteroids.begin();

    while (start_asteroids != asteroids.end()) {
        start_bullets = bullets.begin();
        while (start_bullets != bullets.end()) {//Проходимся по вектору всех пуль и проверяем их + их координаты
            if (!start_bullets->isAlive()) {//если пуля есть, то переходим к след
                ++start_bullets;
                continue;
            }
            if (start_asteroids->checkPoint(start_bullets->getPosition())){//Если позиция пули и астероида =
                start_bullets->kill();//удаляем пулю
                start_asteroids->breakDown();//Ломаем астероид
                if(!start_bullets->isItEnemy())//если пуля попала в астероид, то + очки
                Score++;
                break;
            }
            ++start_bullets;//Следующая пуля
        }
        ++start_asteroids;//Следующий астероид
    }
    start_bullets = bullets.begin();
////////////////////////////Рома
    while (start_bullets != bullets.end()) {
        if (!start_bullets->isAlive() || start_bullets->isItEnemy()) {//если пуля мертва или пуля противника, то мы ее убиваем
            {
                start_bullets->kill();
                
            }
            ++start_bullets;
            continue;
        }
        if (UFO != nullptr && UFO->checkPoint(start_bullets->getPosition()))//сравнение координат пули и нло
        {
            UFO->punch(true);//удар прошелся по нло
            start_bullets->kill();
        }
        // Взаимодействие с тарелкой   
        ++start_bullets;
        }
    if (ship.dedinside())//если корабль мертв,то прекращаем обновлять картинки
        return false;
    
    //asteroids.insert(asteroids.end(), new_asteroids.begin(), new_asteroids.end());
    return true;
}
//////////////////////////*it адрес эл вектора
void Level::show(sf::RenderTarget& target) {//Показ объекта
    
    for(std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it)
        target.draw(*it);//Отрисовка пуль

    target.draw(ship);//Отрисовка корабля

    for(std::vector<Asteroid>::iterator it = asteroids.begin(); it != asteroids.end(); ++it)
        target.draw(*it);//Отрисовка астероидов

    if (UFO != nullptr && UFO->isAlive())//еси нло существует и жива
    {
        sf::RenderStates states;
        UFO->draw(target, states);//рисуем нло
    }
    
    std::ostringstream playerScoreString;    // объявили переменную очки игрока
    playerScoreString << Score;// Очки игрока
    text.setString("Score: " + playerScoreString.str());//вывод очков
    target.draw(text);//Отрисовка текста слева сверху экрана
    
}

void Level::start() {
}
