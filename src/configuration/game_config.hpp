#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

namespace app_config::game {
    enum GameActions {
        MOVE_LEFT,
        MOVE_RIGHT,
        MOVE_UP,
        MOVE_DOWN,
        JUMP,
        RUN,
        UNKNOWN,
    };

    static std::unordered_map<int, GameActions> KEY_BINDINGS = {
            {sf::Keyboard::Scan::A, GameActions::MOVE_LEFT},
            {sf::Keyboard::Scan::D, GameActions::MOVE_RIGHT},
            {sf::Keyboard::Scan::W, GameActions::MOVE_UP},
            {sf::Keyboard::Scan::S, GameActions::MOVE_DOWN},
            {sf::Keyboard::Scan::Space, GameActions::JUMP},
            {sf::Keyboard::Scan::LShift, GameActions::RUN},
    };

} // app_config::game
