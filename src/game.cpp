#include "game.h"

Game::Game()
{
    window = SDL_CreateWindow(
        "TheLine",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        500, 500, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    running = true;
    line = new Line(renderer);
}

bool Game::getRunning()
{
    return running;
}

void Game::input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            line->setPoint(event.motion.x, event.motion.y);
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    line->update();
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    line->render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}