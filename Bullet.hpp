#ifndef _BULLET_HPP
#define _BULLET_HPP_

#include <math.h>
#include <SFML/Graphics.hpp>




class Bullet: public sf::Drawable, public sf::Transformable {
    public:
        Bullet(sf::Vector2f position, float angle, bool isenemy);
        ~Bullet();

        bool isAlive();
        void kill();
        bool isItEnemy() { return isenemy; };
        void update(float frametime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        bool is_alive;
        float remaining_life;
        bool isenemy;
        float speed;
        sf::Vector2f direction;
        sf::Sprite bulletSprite;
        
};
#endif
