#ifndef LINE
#define LINE

#include <vector>
#include <SDL2/SDL.h>

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
    std::vector<SDL_Rect> body;
};

#endif