#pragma once

#include "player_condition.h"

#include <configuration/app_config.hpp>
#include <graphics/drawable/drawable_object.hpp>
#include <physics/physical_objects/physical_object.hpp>

class Player : public PhysicalObject {
    using Base = PhysicalObject;

public:
    using Ptr = std::shared_ptr<Player>;

    Player();

    void init();

    void update(double time);

    void process_event(const sf::Event& event);

private:
    PlayerCondition condition_;
    DrawableObject::Ptr player_sprite_ptr_;

    app_config::game::GameActions get_game_action_(const sf::Event& event);

    void process_event_pressed_(const sf::Event& event);

    void process_event_released_(const sf::Event& event);

    void start_move_left_();

    void start_move_right_();

    void stop_move_left_();

    void stop_move_right_();
};