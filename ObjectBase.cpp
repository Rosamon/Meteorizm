#include "ObjectBase.h"

//-----------------------------------------------------------
// ����� ������� ����� Object
ObjectBase::ObjectBase() {};
ObjectBase::~ObjectBase() {};


bool ObjectBase::isAlive() {
    return is_Alive;
}


int ObjectBase::getLevel() {
    return level;
}