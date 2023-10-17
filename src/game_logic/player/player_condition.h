#pragma once

struct PlayerCondition {
private:
    bool moving_left_ = false;
    bool moving_right_ = false;
    bool moving_up_ = false;
    bool moving_down_ = false;
    bool jumping_ = false;
    bool running_ = false;

public:
    [[nodiscard]] bool is_moving_left() const noexcept;

    [[nodiscard]] bool is_moving_right() const noexcept;

    [[nodiscard]] bool is_moving_up() const noexcept;

    [[nodiscard]] bool is_moving_down() const noexcept;

    [[nodiscard]] bool is_running() const noexcept;

    [[nodiscard]] bool is_jumping() const noexcept;

    void set_moving_left(bool flag) noexcept;

    void set_moving_right(bool flag) noexcept;

    void set_moving_up(bool flag) noexcept;

    void set_moving_down(bool flag) noexcept;

    void set_running_aboba(bool flag) noexcept;

    void set_jumping(bool flag) noexcept;
};
