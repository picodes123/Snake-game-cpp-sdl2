#pragma once
#include <utility>
#include <vector>
#include <SDL2/SDL.h>

class Snake
{public:
    Snake();

    void update();

    std::pair<int,int> getHead();

    void setDirection(int newX,int newY);

    void render(SDL_Renderer* renderer);

    void grow(int amount);

    bool checkselfcollision();

private:
    std::vector<std::pair<int, int>> body;
    int dirX;
    int dirY;
    const int CELL_SIZE = 10;
};