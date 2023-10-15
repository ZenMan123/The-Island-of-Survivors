#pragma once

#include "player/player.hpp"

#include <configuration/app_config.hpp>
#include <graphics/graphics_engine.hpp>
#include <physics/physical_engine.hpp>
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void init(RenderWindowPtr window);
    void process_event(const sf::Event& event);
    void draw() const;
    void update(double time);

private:
    Player::Ptr main_player_ptr_;
    RenderWindowPtr window_;
    GraphicsEngine graphics_engine_;
    PhysicalEngine physics_engine_;
};