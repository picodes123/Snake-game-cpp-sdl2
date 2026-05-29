#pragma once
#include <SDL2/SDL.h>
#include "Snake.h"

class Game
{public:
    void run();
    std::pair<int,int> food;
    int score;

private:
    Uint32 lastMoveTime; 
    Snake snake;
    Snake update;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;};