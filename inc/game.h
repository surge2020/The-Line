#ifndef GAME
#define GAME

#include <SDL2/SDL.h>
#include "line.h"

class Game {
public:
    Game();
    bool getRunning();
    void input();
    void logic();
    void update();
    void render();
    void clean();
private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    bool running;
    Line* line;
};

#endif