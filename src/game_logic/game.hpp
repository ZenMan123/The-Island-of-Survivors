#pragma once

#include "player/player.hpp"

#include <configuration/app_config.hpp>
#include <graphics/graphics_engine.hpp>
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void init(RenderWindowPtr window);
    void process_event(const sf::Event& event);
    void draw() const;
    void Update(double time);

private:
    Player main_player_;
    RenderWindowPtr window_;
    GraphicsEngine graphics_engine_;
};