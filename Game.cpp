#include "Game.h"
#include <iostream>
#include "Snake.h"
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>

using namespace std;

void Game::run()
{
    lastMoveTime = SDL_GetTicks(); 
    const int moveDelay = 70; //how much ms snake update aka snake speed
    score = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) //initialize screen
    {
        cout << "SDL Init Error: " << SDL_GetError() << endl;
        return;
    }
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN); //800x600 game window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //render the screen

    srand(time(NULL));  //for snake food 
    int x = (rand()%80) * 10;
    int y = (rand()%60) * 10;
    food = {x,y};


    isRunning = true;
    while (isRunning)
    {
        Uint32 currentTime = SDL_GetTicks(); 

        if (currentTime - lastMoveTime > moveDelay){
            snake.update();
            lastMoveTime = currentTime;

            auto head = snake.getHead();

            if (head.first == food.first && head.second == food.second){  //check if snake eat food, hence increase snake length and generate new food

                snake.grow(5);
                food = {(rand()%80)* 10, (rand()%60)* 10};
                score++;

            } 

            if (snake.checkselfcollision()) {  //close if self collision

            isRunning = false;

           }

           if (head.first<0 || head.first>=800 || head.second<0 || head.second >=600)  //for collision with wall(screen height and width)
           {
             isRunning = false;
           }
           
        }


        
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isRunning = false;

            if (event.type==SDL_KEYDOWN) //detect keyboard input
            {
                if(event.key.keysym.sym == SDLK_UP){snake.setDirection(0,-1);}
                if(event.key.keysym.sym == SDLK_DOWN){snake.setDirection(0,1);}
                if(event.key.keysym.sym == SDLK_LEFT){snake.setDirection(-1,0);}
                if(event.key.keysym.sym == SDLK_RIGHT){snake.setDirection(1,0);}
            }
            
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        
        //draw snake
        snake.render(renderer);

        
        SDL_SetRenderDrawColor(renderer,255,0 ,0 ,255); //red color for food

        SDL_Rect foodRect = {food.first, food.second, 10, 10}; 
        SDL_RenderFillRect(renderer, &foodRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
};