#pragma once

#include "object_border.hpp"


// Common interface for physical objects 
class PhysicalObject {
public:
    Vec2 speed = Vec2(0.0);

    Vec2 position;

    // Constructors
    PhysicalObject(const Vec2& position) noexcept;
};
