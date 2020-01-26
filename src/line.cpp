#include "line.h"
#include <iostream>

Line::Line(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

void Line::setPoint(float x, float y)
{
    pointRectX = x;
    pointRectY = y;
    createBody();
}

void Line::createBody()
{
    body.clear();
    float k = pointRectY / pointRectX;
    std::cout << pointRectY << std::endl;
    std::cout << pointRectX << std::endl;
    std::cout << k << std::endl;
    for (int x = 0; x < pointRectX; ++x) {
        float y = k * x;
        SDL_Rect tempRect = {x, (int)y, 1, 1};
        body.push_back(tempRect);
    }
}

void Line::update()
{
    pointRect = {pointRectX, pointRectY, 1, 1};
}

void Line::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &pointRect);
    for (SDL_Rect bodyPoint : body) {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &bodyPoint);
    }
}