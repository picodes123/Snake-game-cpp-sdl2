#include "Snake.h"
Snake::Snake()
{
    body.push_back({100, 100});
    body.push_back({90, 100});
    body.push_back({80, 100});

    dirX = 1;
    dirY = 0;
}


void Snake::update(){

    for (int i = body.size()-1; i > 0; i--){

        body[i]=body[i-1];
    }

    
    body[0].first += dirX * CELL_SIZE;
    body[0].second += dirY * CELL_SIZE;
}

void Snake::render(SDL_Renderer* renderer){
    for (int i = 0; i < body.size(); i++)
    {
        SDL_Rect rect = {body[i].first, body[i].second, 10, 10};
        SDL_RenderFillRect(renderer, &rect);
    } }

void Snake::grow(int amount){
    for(int i =0; i < amount; i++)
    body.push_back(body.back());
}

std::pair<int,int> Snake::getHead(){

    return body[0];

}

void Snake::setDirection(int newX,int newY){

    if (newX == -dirX && newY == -dirY)
    {
        return;
    }
    
    
     dirX = newX;
     dirY = newY;

}

bool Snake::checkselfcollision(){

    auto head = body[0];
    for (int i=1; i<body.size(); i++)
    {
        if (body[i]==head)
        {
            return true;
        }
        
    }

    return false;
    
}