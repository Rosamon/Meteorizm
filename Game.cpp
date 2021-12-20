#include "Game.h"
#include "Level.h"

using namespace sf;
Game::Game():
    running(true), lives(3) {
}

Game::~Game() {
    window.close();
}

int Game::run() {
    createWindow();
    sf::Clock my_timer;// для контроля действий тарелки
    Level level;
    sf::Clock clock;

    level.start();
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close(); }
            if (event.type == sf::Event::Closed) {
                window.close();
				window.create(sf::VideoMode(APP_WIDTH, APP_HEIGHT), "GameOver", sf::Style::Close);
                window.setKeyRepeatEnabled(true);
                window.setFramerateLimit(APP_FPS);
                Texture Texture_End;
                Texture_End.loadFromFile("images\\GameOver.png");
                Sprite GameEnd;
                GameEnd.setTexture(Texture_End);//������� � ���� ������ Texture (��������)
                window.draw(GameEnd);
                window.display();
                //Sleep(5000);
                return EXIT_SUCCESS;
                return EXIT_SUCCESS;
            }
            level.onEvent(event);
        }

        window.clear();
        int buff = my_timer.getElapsedTime().asMilliseconds();// 
        level.update(clock.restart().asMilliseconds(), buff);
        if (buff >= 6030)
        {
            my_timer.restart();// Перезапуск таймера для тарелки
        }
        level.show(window);
        window.display();
    }
    return EXIT_SUCCESS;
}
void Game::createGameWindow() {
    window.create(sf::VideoMode(APP_WIDTH, APP_HEIGHT), APP_TITLE, sf::Style::Close);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(APP_FPS);
    Texture Texture_Start,button_start,button_exit;
    button_start.loadFromFile("images\\start.png");
    button_exit.loadFromFile("images\\exit.png");
    Texture_Start.loadFromFile("images\\Ver2.png");
    Sprite GamePic,StartSprite,ExitSprite;
    bool isMenu = 1;
    int menuNum = 0;
    GamePic.setTexture(Texture_Start);//ïåðåäà¸ì â íåãî îáúåêò Texture (òåêñòóðû)
    StartSprite.setTexture(button_start);
    ExitSprite.setTexture(button_exit);
    StartSprite.setPosition(100, 300);
    ExitSprite.setPosition(100, 400);
    window.draw(GamePic);
    while (isMenu)
    {

        menuNum = 0;

        if (IntRect(100, 300, 150, 360).contains(Mouse::getPosition(window))) { StartSprite.setColor(Color::Green); menuNum = 1; }
        if (IntRect(100, 400, 150, 460).contains(Mouse::getPosition(window))) { ExitSprite.setColor(Color::Red); menuNum = 2; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 2) { window.close(); system("exit"); };//åñëè íàæàëè ïåðâóþ êíîïêó, òî âûõîäèì èç ìåíþ 
            if (menuNum == 1) { window.clear(Color::Black); isMenu = false; }
            if (Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close(); system("exit"); }
        

        }

        window.draw(GamePic);
        window.draw(StartSprite);
        window.draw(ExitSprite);

        window.display();
    }
    // Îòðèñîâêà îêíà
    
    
}

void Game::createWindow() {
    if (window.isOpen())
        window.close();

    window.create(sf::VideoMode(APP_WIDTH, APP_HEIGHT), APP_TITLE, sf::Style::Close);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(APP_FPS);
}
