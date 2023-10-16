#include "game_map.h"

GameMap::GameMap() = default;

void GameMap::init() {
    
}

void GameMap::update(double time) {
    for (const auto& object : objects_) {
        object->update(time);
    }
}
