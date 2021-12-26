#include "Bullet.hpp"
#ifndef DEG2RAD
#define DEG2RAD 3.14159f / 180.0f
#endif // !DEG2RAD

sf::Texture bulletTexture;
Bullet::Bullet(sf::Vector2f position, float angle, bool isenemy):
    is_alive(true), isenemy(isenemy),
    remaining_life(10000.f),
    direction(cos(angle * DEG2RAD), sin(angle * DEG2RAD)) {

    bulletSprite.setPosition(position);
    bulletSprite.setOrigin(5,5);
    setPosition(position);
    bulletTexture.loadFromFile("images\\Kursa4.png");
    bulletSprite.setTexture(bulletTexture);
    if (!isenemy)
    {
        bulletSprite.setTextureRect(sf::IntRect(59, 377, 14, 31));
        speed = 0.8f;
    }
    else
    {
        speed = 0.4f;
        bulletSprite.setTextureRect(sf::IntRect(145, 377, 19, 31));//вниз
        bulletSprite.setRotation(angle-90);
       
    }
    
}

Bullet::~Bullet() {
}

bool Bullet::isAlive() {
    return is_alive;
}

void Bullet::update(float frametime) {
    if (!is_alive) return;

    remaining_life -= frametime;
    if (remaining_life <= 0) is_alive = false;

    
    sf::Vector2f distance = direction * speed * frametime;
    move(distance);
    bulletSprite.move(distance);
    
    
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(bulletSprite);
}

void Bullet::kill() {
    is_alive = false;
}
