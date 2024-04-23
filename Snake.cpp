#include "Snake.h"
Snake::Snake() {
    std::pair<int, int> head_placement = { 0, 0 };
    placement.push_back(head_placement);
}

void Snake::drag_tail() {
    for (int i = 0; i < placement.size() - 1; i++) {
        placement[i].first = placement[i + 1].first;
        placement[i].second = placement[i + 1].second;
    }
}

void Snake::move_left() {
    drag_tail();
    placement[placement.size() - 1].second--;
}

void Snake::move_right() {
    drag_tail();
    placement[placement.size() - 1].second++;
}

void Snake::move_down() {
    drag_tail();
    placement[placement.size() - 1].first++;
}

void Snake::move_up() {
    drag_tail();
    placement[placement.size() - 1].first--;
}

void Snake::size_up() {
    std::pair<int, int> new_part_placement;
    int size = placement.size();
    if (heading == 'd' || heading == 'a') {
        new_part_placement = std::make_pair(placement[size - 1].first, placement[size - 1].second + (heading == 'd' ? 1 : -1));
    }
    else {
        new_part_placement = std::make_pair(placement[size - 1].first + (heading == 's' ? 1 : -1), placement[size - 1].second);
    }
    placement.insert(placement.begin(), new_part_placement);
}

bool Snake::on_board(int board_size) {
    for (int i = 0; i < placement.size(); i++) {
        if (!(placement[i].first >= 0 && placement[i].first < board_size)) return false;
        if (!(placement[i].second >= 0 && placement[i].second < board_size)) return false;
    }
    return true;
}

bool Snake::bites_tail() {
    for (int i = 0; i < placement.size(); i++) {
        for (int j = 0; j < placement.size(); j++) {
            if (i != j) {
                if ((placement[i].first == placement[j].first) && (placement[i].second == placement[j].second)) return true;
            }
        }
    }
    return false;
}
