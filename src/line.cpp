#include "line.h"
#include <iostream>
//#include <strstream>
#include <sstream>
#include <string>

Line::Line(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    pointRectX = 0;
    pointRectY = 0;
    k = 0;
    TTF_Init();
    font = TTF_OpenFont("res/FreeSans.ttf", 14);
    color = {255, 255, 255};
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
    k = pointRectY / pointRectX;
    if (k < 1) {
        for (int x = 0; x < pointRectX; ++x) {
            float y = k * x;
            SDL_Rect tempRect = {x, (int)y, 1, 1};
            body.push_back(tempRect);
        }
    }
    else {
        for (int y = 0; y < pointRectY; ++y) {
            float x = y / k;
            SDL_Rect tempRect = {(int)x, y, 1, 1};
            body.push_back(tempRect);
        }
    }
    
}

void Line::update()
{
    pointRect = {(int)pointRectX, (int)pointRectY, 1, 1};
}

void Line::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &pointRect);
    for (SDL_Rect bodyPoint : body) {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &bodyPoint);
    }   

    std::stringstream stream;
    stream << "Y: " << pointRectY << " X: " << pointRectX << " K: " << k;
    SDL_Surface* surface = 
        TTF_RenderText_Solid(font, stream.str().c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {0, 480, 300, 20};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}