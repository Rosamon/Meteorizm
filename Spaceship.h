#ifndef _SPACESHIP_HPP_
#define _SPACESHIP_HPP_


#include <SFML/Graphics.hpp>
#include "Constants.h"
using namespace sf;
class Spaceship: public sf::Drawable, public sf::Transformable {

    public:
        Spaceship();
        ~Spaceship();



};
#endif
