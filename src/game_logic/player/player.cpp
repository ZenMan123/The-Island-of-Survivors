#include "graphics/graphics_context.hpp"
#include "player.hpp"
#include "physics/physical_context.hpp"

Player::Player() {
    Resource::Ptr resource = std::make_shared<ColorResource>(sf::Color::Green);
    player_sprite_ptr_ = std::make_shared<DrawableObject>(this->position, Vec2(1.0), resource);
    GraphicsContext::GetInstance()->drawable_objects.insert(player_sprite_ptr_);
}

void Player::init(){};

void Player::process_event(const sf::Event& event) {
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
            stop_move_left_();
            break;

        case app_config::game::GameActions::MOVE_RIGHT:
            stop_move_right_();
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
    if (!condition_.is_moving_left()) {
        Base::speed += Vec2(-5.0, 0.0);
        condition_.set_moving_left(true);
    }
}

void Player::start_move_right_() {
    if (!condition_.is_moving_right()) {
        Base::speed += Vec2(5.0, 0.0);
        condition_.set_moving_right(true);
    }
}

void Player::stop_move_left_() {
    if (condition_.is_moving_left()) {
        Base::speed -= Vec2(-5.0, 0.0);
        condition_.set_moving_left(false);
    }
}

void Player::stop_move_right_() {
    if (condition_.is_moving_right()) {
        Base::speed -= Vec2(5.0, 0.0);
        condition_.set_moving_right(false);
    }
}
