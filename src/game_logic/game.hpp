#pragma once

#include "game_map/game_map.hpp"
#include "player/player.hpp"

#include <graphics/graphics_engine.hpp>
#include <physics/physical_engine.hpp>

class Game {
public:
    Game();

    void init(RenderWindowPtr window);

    void process_event(const sf::Event& event);

    void draw() const;

    void update(double time);

private:
    Player::Ptr main_player_ptr_;
    GameMap game_map_;

    RenderWindowPtr window_;
    GraphicsEngine graphics_engine_;
    PhysicalEngine physics_engine_;
};
