#include "ObjectBase.h"

//-----------------------------------------------------------
// Здесь базовый класс Object
ObjectBase::ObjectBase() {
    TouchBox = sf::FloatRect(10,10,36,36);
};
ObjectBase::~ObjectBase() {};


bool ObjectBase::isAlive() {
    return is_Alive;
}


int ObjectBase::getLevel() {
    return level;
}

sf::FloatRect ObjectBase::getTouchBox() {
    return TouchBox;
}