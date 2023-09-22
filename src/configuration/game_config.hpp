#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

namespace app_config::game {
    enum class GameActions {
        MOVE_LEFT,
        MOVE_RIGHT,
        JUMP,
        RUN,
    };

    std::unordered_map<int, GameActions> KEY_BINDINGS = {
            {sf::Keyboard::A, GameActions::MOVE_LEFT},
            {sf::Keyboard::D, GameActions::MOVE_RIGHT},
            {sf::Keyboard::Space, GameActions::JUMP},
            {sf::Keyboard::LShift, GameActions::RUN}
    };

} // app_config::game
