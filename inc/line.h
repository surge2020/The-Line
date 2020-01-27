#ifndef LINE
#define LINE

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Line {
public:
    Line(SDL_Renderer* renderer);
    void setPoint(float x, float y);
    void createBody();
    void update();
    void render();
private:
    SDL_Renderer* renderer;
    SDL_Rect pointRect;
    float pointRectX;
    float pointRectY;
    float k;
    std::vector<SDL_Rect> body;
    TTF_Font* font;
    SDL_Color color;
};

#endif