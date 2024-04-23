#include "Board.h"
Board::Board(int size) {
    board_size = size;
    for (int i = 0; i < board_size; i++) {
        std::vector<char> v;
        for (int j = 0; j < board_size; j++) {
            v.push_back(' ');
        }
        content.push_back(v);
    }
}

void Board::set_board_size(int n) {
    board_size = n;
}

void Board::empty_board() {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (content[i][j] != '0') {
                content[i][j] = ' ';
            }
        }
    }
}

void Board::print_board() {
    for (int i = 0; i < board_size + 12; i++) std::cout << "#";
    std::cout << std::endl;
    for (int i = 0; i < board_size; i++) {
        std::cout << "#";
        for (int j = 0; j < board_size; j++) {
            std::cout << content[i][j] << " ";
        }
        std::cout << "#" << std::endl;
    }
    for (int i = 0; i < board_size + 12; i++) std::cout << "#";
    std::cout << std::endl;
}

void Board::put_apple(Apple& apple) {
    std::pair<int, int> placement = apple.drop(board_size);
    content[placement.first][placement.second] = '0';
}

void Board::put_snake(Snake& snake) {
    for (int i = 0; i < snake.placement.size(); i++) {
        content[snake.placement[i].first][snake.placement[i].second] = '*';
    }
}

bool Board::snake_ate_apple(Snake& snake) {
    std::pair<int, int> snake_head_placement = snake.placement[snake.placement.size() - 1];
    if (content[snake_head_placement.first][snake_head_placement.second] == '0') return true;
    return false;
}