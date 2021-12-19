#ifndef _SPACESHIP_HPP_
#define _SPACESHIP_HPP_


#include <SFML/Graphics.hpp>
#include "Constants.h"
using namespace sf;
class Spaceship: public sf::Drawable, public sf::Transformable {

    public:
        Spaceship();
        ~Spaceship();

  float x, y, w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
        int dir = 0; //направление (direction) движения игрока
        Image image;//изображение
        Texture texture;// текстура
        Sprite sprite;// спрайт
         void reset();
        void update(float time);
        void interactionWithMap();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void onEvent(const sf::Event& event);


};
#endif
