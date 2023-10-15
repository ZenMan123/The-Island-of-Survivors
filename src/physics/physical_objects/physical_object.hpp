#pragma once

#include "object_border.hpp"


// Common interface for physical objects 
class PhysicalObject {
    bool movable_;
    double reversed_weight_;
    double restitution_;

public:
    using Ptr = std::shared_ptr<PhysicalObject>;

    Vec2 speed = Vec2(0.0);

    Vec2 position;
    ObjectBorder::Ptr border;

    // Constructors
    PhysicalObject(const Vec2& position, double restitution);
    
    PhysicalObject(const Vec2& position, double weight, double restitution);

    // Common methods
    void intersect(PhysicalObject::Ptr other, std::vector<Intersection>& intersections) const;

    void update(double time) noexcept;

    void apply_intersection(const Intersection& intersection, PhysicalObject::Ptr other) noexcept;
};
