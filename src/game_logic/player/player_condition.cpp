#include "player_condition.h"

[[nodiscard]] bool PlayerCondition::is_moving_left() const noexcept {
    return moving_left_;
}

[[nodiscard]] bool PlayerCondition::is_moving_right() const noexcept {
    return moving_right_;
}

[[nodiscard]] bool PlayerCondition::is_moving_up() const noexcept {
    return moving_up_;
}

[[nodiscard]] bool PlayerCondition::is_moving_down() const noexcept {
    return moving_down_;
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

void PlayerCondition::set_moving_up(bool flag) noexcept {
    moving_up_ = flag;
}

void PlayerCondition::set_moving_down(bool flag) noexcept {
    moving_down_ = flag;
}

void PlayerCondition::set_running_aboba(bool flag) noexcept {
    running_ = flag;
}

void PlayerCondition::set_jumping(bool flag) noexcept {
    jumping_ = flag;
}