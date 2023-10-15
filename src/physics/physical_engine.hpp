#pragma once

#include "physical_context.hpp"


struct ObjectsIntersection {
    PhysicalObject::Ptr first;
    PhysicalObject::Ptr second;
    Intersection intersection;
};


// 2D graphics engine
class PhysicalEngine {
    inline static std::vector<Intersection> intersectoins_buffer_;

    PhysicalContext* context_;
    std::vector<ObjectsIntersection> intersections_;

    // Private functions
    void apply_intersections() noexcept;

public:
    // Constructors
    PhysicalEngine() noexcept;

    void init() noexcept;

    // Common functions
    void update(double time);
};
