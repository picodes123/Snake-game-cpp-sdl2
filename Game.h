#pragma once
#include <SDL2/SDL.h>

class Game
{public:
    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;};