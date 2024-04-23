#include "Apple.h"
std::pair<int, int> Apple::drop(int board_size) {
    return { rand() % board_size, rand() % board_size };
}