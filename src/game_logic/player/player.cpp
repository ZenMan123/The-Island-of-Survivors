#include "graphics/drawable_objects/resources/rectangle_resource.hpp"
#include "graphics/drawable_objects/resources/circle_resource.hpp"
#include "graphics/graphics_context.hpp"
#include "player.hpp"
#include "physics/physical_context.hpp"
#include <SFML/Window/Keyboard.hpp>

Player::Player() = default;

Player::~Player() noexcept {

}

void Player::init() {
    Base::init(PhysicalObjectConfig(1.0, .1));
    border = BoxBorder::make(Vec2(0.0, -1.0), Vec2(1.0, 0.0));
    Base::position = Vec2(1, 3);

    initialize_player_sprite();
    PhysicalContext::GetInstance()->physical_objects.insert(this->shared_from_this());
    GraphicsContext::GetInstance()->drawable_objects.insert(player_sprite_ptr_);
};

void Player::initialize_player_sprite() {
    Resource::Ptr resource = CircleResource::make(sf::Color::Green);
    player_sprite_ptr_ = DrawableObject::make(Vec2(1.0), resource);
    player_sprite_ptr_->follow(this->shared_from_this());
}

void Player::update(double time){};

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

        case app_config::game::GameActions::MOVE_UP:
            start_move_up_();
            break;

        case app_config::game::GameActions::MOVE_DOWN:
            start_move_down_();
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

        case app_config::game::GameActions::MOVE_UP:
            stop_move_up_();
            break;

        case app_config::game::GameActions::MOVE_DOWN:
            stop_move_down_();
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
        Base::strength += Vec2(-5.0, 0.0);
        condition_.set_moving_left(true);
    }
}

void Player::start_move_right_() {
    if (!condition_.is_moving_right()) {
        Base::strength += Vec2(5.0, 0.0);
        condition_.set_moving_right(true);
    }
}

void Player::start_move_up_() {
    if (!condition_.is_moving_up()) {
        Base::strength += Vec2(0.0, 5.0);
        condition_.set_moving_up(true);
    }
}

void Player::start_move_down_() {
    if (!condition_.is_moving_down()) {
        Base::strength += Vec2(0.0, -5.0);
        condition_.set_moving_down(true);
    }
}

void Player::stop_move_left_() {
    if (condition_.is_moving_left()) {
        Base::strength -= Vec2(-5.0, 0.0);
        condition_.set_moving_left(false);
    }
}

void Player::stop_move_right_() {
    if (condition_.is_moving_right()) {
        Base::strength -= Vec2(5.0, 0.0);
        condition_.set_moving_right(false);
    }
}

void Player::stop_move_up_() {
    if (condition_.is_moving_up()) {
        Base::strength -= Vec2(0.0, 5.0);
        condition_.set_moving_up(false);
    }
}

void Player::stop_move_down_() {
    if (condition_.is_moving_down()) {
        Base::strength -= Vec2(0.0, -5.0);
        condition_.set_moving_down(false);
    }
}
