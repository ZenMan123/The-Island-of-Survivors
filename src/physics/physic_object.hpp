#pragma once

#include <common/math/vec2.hpp>


// Common interface for physic 
class PhysicObject {
public:
    Vec2 speed = Vec2(0.0);

    Vec2 position;

    // Constructors
    PhysicObject(const Vec2& position) noexcept;
};
