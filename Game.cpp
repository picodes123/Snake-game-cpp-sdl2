#include "Game.h"
#include <iostream>
using namespace std;

void Game::run()
{
    lastMoveTime = SDL_GetTicks();
    const int moveDelay = 10;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL Init Error: " << SDL_GetError() << endl;
        return;
    }
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    isRunning = true;
    while (isRunning)
    {
        Uint32 currentTime = SDL_GetTicks();

        if (currentTime - lastMoveTime > moveDelay)
        {
            snake.update();
            lastMoveTime = currentTime;
        }
        
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isRunning = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

        auto head = snake.getHead();

        SDL_Rect rect={head.first, head.second, 20, 20};
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}