#pragma once
#include <utility>
#include <vector>

class Snake
{public:
    Snake();

    void update();

private:
    std::vector<std::pair<int, int>> body;
    int dirX;
    int dirY;
};