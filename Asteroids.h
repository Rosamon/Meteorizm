#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_


// интерфейс класса Asteroid
class Asteroid{

public:
    Asteroid(int level);
    ~Asteroid();

    int getLvl(); // получить значение уровня
    bool isAlive(); // получить состояние астероида
    void breakDown(); // действие при попадании в астероид

private:
    int lvl; // значение уровня 
    bool isAlive; // состояние астероида
};
#endif