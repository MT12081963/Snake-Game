#pragma once
#include "Apple.h"
#include "Snake.h"

class Board {
private:
    int board_size;
    std::vector<std::vector<char>> content;
public:
    Board(int size);
    void set_board_size(int n);
    void empty_board();
    void print_board();
    void put_apple(Apple& apple);
    void put_snake(Snake& snake);
    bool snake_ate_apple(Snake& snake);
};