#pragma once

#include <graphics/graphics_context.hpp>
#include <physics/physical_context.hpp>

class GameMap {
    std::vector<DrawableObject::Ptr> objects_;

public:
    GameMap();

    void init();

    void update(double time);
};