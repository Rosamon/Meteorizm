#include <SFML/Graphics.hpp>

class Enemy: public ObjectBase, public sf::Drawable, public sf::Transformable
{
public:
	Enemy(): ObjectBase() {};
	~Enemy();
	Enemy(sf::Vector2f position);
	void punched();// окрашивает в красный или белый, считает количество попаданий
	void punch(bool hit) {isHit = hit;};
    bool checkPoint(sf::Vector2f point);
    void update(float frametime);
    void draw(sf::RenderTarget& target, sf::RenderStates states);
    bool isAlive(){return alive;};
    int getLevel(){return level;};
private:
	int level;
    bool alive, isHit;
    sf::Vector2f direction; // (-1;0) || (1;0)
    Texture enemyUFOsprite;
};