#include <configuration/game_config.hpp>
#include <physics/physical_objects/physical_object.hpp>
#include <SFML/Graphics.hpp>

class Player : public PhysicalObject {
    using Base = PhysicalObject;

public:
    Player();

    void Update(double time) {
        Base::update(time);
    }

    void ProcessEvent(const sf::Event& event) {
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

private:
    app_config::game::GameActions get_game_action_(const sf::Event& event) {
        if (!app_config::game::KEY_BINDINGS.contains(event.key.scancode)) {
            return app_config::game::GameActions::UNKNOWN;
        }

        return app_config::game::KEY_BINDINGS[event.key.scancode];
    }

    void process_event_pressed_(const sf::Event& event) {
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

    void process_event_released_(const sf::Event& event) {
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

    void start_move_left_() {
        Base::speed = Vec2(-5.0, 0.0);
    }

    void start_move_right_() {
        Base::speed = Vec2(5.0, 0.0);
    }

    void stop_move_() {
        Base::speed = Vec2(0.0, 0.0);
    }

};