#include "SingleGame.h"
SingleGame::SingleGame(int size) : board_size(size), board(size), snake_lenth(1) {}

MoveResult SingleGame::single_move() {
    bool apple_was_eaten = false;
    std::cout << "press button: a-left, d-rigt, w-up, s-down" << std::endl;
    char user_response;
    std::cin >> user_response;
    switch (user_response) {
    case 'a':
        snake.heading = 'a';
        snake.move_left();
        break;
    case'd':
        snake.heading = 'd';
        snake.move_right();
        break;
    case 'w':
        snake.heading = 'w';
        snake.move_up();
        break;
    case 's':
        snake.heading = 's';
        snake.move_down();
        break;
    default:
        std::cout << "try again" << std::endl;
        return GAME_CONTINUES;
    }
    if (!snake.on_board(board_size)) return GAME_OVER;
    if (snake.bites_tail()) return GAME_OVER;
    if (board.snake_ate_apple(snake)) {
        snake_lenth++;
        apple_was_eaten = true;
    }
    board.empty_board();
    board.put_apple(apple);
    board.put_snake(snake);
    board.print_board();
    std::cout << std::endl << "snake lenth " << snake_lenth << std::endl;
    if (apple_was_eaten) {
        return APPLE_EATEN;
    }
    else {
        return GAME_CONTINUES;
    }
}

void SingleGame::start() {
    board.put_snake(snake);
    board.print_board();
    MoveResult result;
    do {
        result = single_move();
        if (result == APPLE_EATEN) {
            snake.size_up();
        };
    } while(result != GAME_OVER);
    std::cout << "Game over" << std::endl << "Score:" << snake_lenth << std::endl;
}