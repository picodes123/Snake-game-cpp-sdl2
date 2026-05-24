#pragma once
#include <utility>
#include <vector>

class Snake
{public:
    Snake();

    void update();

    std::pair<int,int> getHead();

private:
    std::vector<std::pair<int, int>> body;
    int dirX;
    int dirY;
};