#pragma once

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void process_event(const sf::Event& event);

private:
    void process_key_pressed_(const sf::Event& event);
    void process_key_released_(const sf::Event& event);
};