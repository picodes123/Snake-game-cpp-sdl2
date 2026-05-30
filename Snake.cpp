#include "Snake.h"
Snake::Snake()  //snake body
{
    body.push_back({100, 100});
    body.push_back({90, 100});
    body.push_back({80, 100});

    dirX = 1;
    dirY = 0;
}


//for snake update
void Snake::update(){

    for (int i = body.size()-1; i > 0; i--){

        body[i]=body[i-1];
    }

    
    body[0].first += dirX * CELL_SIZE;
    body[0].second += dirY * CELL_SIZE;
}


//draws the snake body 
void Snake::render(SDL_Renderer* renderer){
    for (int i = 0; i < body.size(); i++)
    {
        SDL_Rect rect = {body[i].first, body[i].second, 10, 10};
        SDL_RenderFillRect(renderer, &rect);
    } }


//how much snake grow after eating food
void Snake::grow(int amount){
    for(int i =0; i < amount; i++)
    body.push_back(body.back());
}


//for snake head
std::pair<int,int> Snake::getHead(){

    return body[0];

}


//to make snake move in direction and condition for it to not move opposite dir
void Snake::setDirection(int newX,int newY){

    if (newX == -dirX && newY == -dirY)
    {
        return;
    }
    
    
     dirX = newX;
     dirY = newY;

}


//for checking snakes self collision
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