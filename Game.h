#pragma once
#include <SDL2/SDL.h>
#include "Snake.h"

class Game
{public:
    void run();

private:
    Snake snake;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;};