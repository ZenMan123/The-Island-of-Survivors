#pragma once

#include <graphics/game_objects/game_object.hpp>
#include <graphics/graphics_context.hpp>
#include <physics/physical_context.hpp>

class GameMap {
    std::vector<GameObject::Ptr> objects_;

public:
    GameMap();

    void init();

    void update(double time);
};