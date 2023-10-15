#pragma once

#include <configuration/app_config.hpp>
#include <graphics/graphics_engine.hpp>
#include <SFML/Graphics.hpp>
#include <player/player.hpp>

class Game {
public:
    Game();
    void Init(RenderWindowPtr window);
    void process_event(const sf::Event& event);
    void Draw() const;
    void Update(double time);

private:
    Player main_player_;
    RenderWindowPtr window_;
    GraphicsEngine graphics_engine_;
};