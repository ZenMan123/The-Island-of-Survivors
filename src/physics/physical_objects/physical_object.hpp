#pragma once

#include "object_border.hpp"


// Common interface for physical objects 
class PhysicalObject {
public:
    using Ptr = std::shared_ptr<PhysicalObject>;

    Vec2 speed = Vec2(0.0);

    Vec2 position;
    ObjectBorder::Ptr border;

    // Constructors
    PhysicalObject(const Vec2& position) noexcept;

    // Common methods
    void intersect(PhysicalObject::Ptr other, std::vector<Intersection>& intersections) const;

    void update(double time) noexcept;
};
