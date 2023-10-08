#pragma once

#include <game_logic/game.hpp>
#include <SFML/Graphics.hpp>

class AppRunner {
public:
    AppRunner();
    void run();

private:
    Game game_;
    sf::Window window_;
};