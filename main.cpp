#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include <windows.h>
using namespace sf;
int main()
{
	 srand(time(NULL));
    Game game;
    game.createGameWindow();
    game.createWindow();
   game.run();
	return 0;
}
