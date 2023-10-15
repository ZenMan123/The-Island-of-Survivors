#include "player.hpp"

Player::Player(){};

void Player::Update(double time) {
    Base::update(time);
}

void Player::ProcessEvent(const sf::Event& event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            process_event_pressed_(event);
            break;

        case sf::Event::KeyReleased:
            process_event_released_(event);
            break;

        default:
            break;
    }
}

app_config::game::GameActions Player::get_game_action_(const sf::Event& event) {
    if (!app_config::game::KEY_BINDINGS.contains(event.key.scancode)) {
        return app_config::game::GameActions::UNKNOWN;
    }

    return app_config::game::KEY_BINDINGS[event.key.scancode];
}

void Player::process_event_pressed_(const sf::Event& event) {
    auto value = get_game_action_(event);

    switch (value) {
        case app_config::game::GameActions::MOVE_LEFT:
            start_move_left_();
            break;

        case app_config::game::GameActions::MOVE_RIGHT:
            start_move_right_();
            break;

        case app_config::game::GameActions::JUMP:
            break;

        case app_config::game::GameActions::RUN:
            break;

        case app_config::game::GameActions::UNKNOWN:
            break;

        default:
            break;
    }
}

void Player::process_event_released_(const sf::Event& event) {
    auto value = get_game_action_(event);

    switch (value) {
        case app_config::game::GameActions::MOVE_LEFT:
            stop_move_();
            break;

        case app_config::game::GameActions::MOVE_RIGHT:
            stop_move_();
            break;

        case app_config::game::GameActions::JUMP:
            break;

        case app_config::game::GameActions::RUN:
            break;

        case app_config::game::GameActions::UNKNOWN:
            break;

        default:
            break;
    }
}

void Player::start_move_left_() {
    Base::speed = Vec2(-5.0, 0.0);
}

void Player::start_move_right_() {
    Base::speed = Vec2(5.0, 0.0);
}

void Player::stop_move_() {
    Base::speed = Vec2(0.0, 0.0);
}
