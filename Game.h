#ifndef _GAME_HPP_
#define _GAME_HPP_
#define APP_FPS 60
#define APP_WIDTH 1000
#define APP_HEIGHT 1000
#define APP_TITLE "Roma Rat Rider"

#include <SFML/Graphics.hpp>

class Game {
    public:
        Game();
        ~Game();
        int run();
        void quit();
        void pause();
        void unpause();
        void createGameWindow();
        void createWindow();
        void createPauseWindow();

    private:
        sf::RenderWindow window;
        bool running;
        int lives;
};

#endif
