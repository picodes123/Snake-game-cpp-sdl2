#include "Snake.h"
Snake::Snake()
{
    body.push_back({100, 100});

    dirX = 1;
    dirY = 0;
}

void Snake::update(){
    body[0].first += dirX;
    body[0].second += dirY;

}

std::pair<int,int> Snake::getHead(){

    return body[0];

}