#include "game.h"

int main()
{
    Game game;
    while (game.getRunning()) {
        game.input();
        game.update();
        game.render();
    }
    game.clean();
    return 0;
}