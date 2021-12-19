#include "ObjectBase.h"

//-----------------------------------------------------------
// Здесь базовый класс Object
ObjectBase::ObjectBase() {};
ObjectBase::~ObjectBase() {};


bool ObjectBase::isAlive() {
    return is_Alive;
}


int ObjectBase::getLevel() {
    return level;
}