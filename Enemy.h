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
    void aim(sf::Vector2f position); // направляет пулю в сторону ракеты, принимает его координаты, возвращает указатель на созданный класс
    //раз в 3 секунды стрляет time % 3000
    //list <Bullet> shrapnel();// выпускает несколько снарядов под разным углом вниз
    //
    bool isAlive(){return alive;};
    int getLevel(){return level;};
private:
	int level;
    bool alive, ishit;
    sf::Vector2f direction; // (-1;0) || (1;0)
    Sprite enemyUFOsprite;
};