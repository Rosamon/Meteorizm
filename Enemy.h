#include <SFML/Graphics.hpp>

class Enemy: public ObjectBase, public sf::Drawable, public sf::Transformable
{
public:
	Enemy(): ObjectBase() {};
	~Enemy();
	Enemy(int position);// 1, 2, 3
	void punched();// окрашивает в красный или белый, считает количество попаданий
	void punch(bool hit) {ishit = hit;};
    bool checkPoint(sf::Vector2f point);
    void update(float frametime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool moved(float frametime);// определяет в движении ли объект
    Bullet aim(sf::Vector2f position); // направляет пулю в сторону ракеты, принимает его координаты, возвращает указатель на созданный класс
    //раз в 3 секунды стрляет 
    bool isAlive(){return alive;};
    
private:
	
    bool alive, ishit;
    sf::Vector2f direction; // (-1;0) || (1;0)
    sf::Vector2f position_UFO;
    Sprite enemyUFOsprite;
    sf::Texture enemytexture;
};