#include "player_condition.h"

[[nodiscard]] bool PlayerCondition::is_moving_left() const noexcept {
    return moving_left_;
}

[[nodiscard]] bool PlayerCondition::is_moving_right() const noexcept {
    return moving_right_;
}

[[nodiscard]] bool PlayerCondition::is_running() const noexcept {
    return running_;
}

[[nodiscard]] bool PlayerCondition::is_jumping() const noexcept {
    return jumping_;
}

void PlayerCondition::set_moving_left(bool flag) noexcept {
    moving_left_ = flag;
}

void PlayerCondition::set_moving_right(bool flag) noexcept {
    moving_right_ = flag;
}

void PlayerCondition::set_running(bool flag) noexcept {
    running_ = flag;
}

void PlayerCondition::set_jumping(bool flag) noexcept {
    jumping_ = flag;
}