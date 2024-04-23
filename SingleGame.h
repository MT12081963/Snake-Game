
#include "Board.h"
enum MoveResult {
    GAME_CONTINUES,
    APPLE_EATEN,
    GAME_OVER
};

class SingleGame {
private:
    int board_size;
    Board board;
    Snake snake;
    Apple apple;
    int snake_lenth;
    MoveResult single_move();
public:
    SingleGame(int size);
    void start();
};
#pragma once
