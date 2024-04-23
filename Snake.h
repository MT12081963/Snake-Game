#include<vector>
class Snake {
private:
    void drag_tail();
public:
    std::vector<std::pair<int, int>> placement;
    char heading;
    Snake();
    void move_left();
    void move_right();
    void move_down();
    void move_up();
    void size_up();
    bool on_board(int board_size);
    bool bites_tail();
};
#pragma once
