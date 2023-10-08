#pragma once

#include <configuration/app_config.hpp>
#include <graphics/graphics_engine.hpp>
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void Init(RenderWindowPtr window);
    void process_event(const sf::Event& event);
    void Draw() const;
    void Update(double time);

private:
    void process_key_pressed_(const sf::Event& event);
    void process_key_released_(const sf::Event& event);

    RenderWindowPtr window_;
    GraphicsEngine graphics_engine_;
};