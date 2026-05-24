#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include "Game.h"
using namespace std;

int main(int argc, char* argv[]){

    Game game;
    game.run();


    return 0;
}