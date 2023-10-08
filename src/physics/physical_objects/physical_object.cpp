#include "physical_object.hpp"


// Constructors
PhysicalObject::PhysicalObject(const Vec2& position) noexcept
    : position(position)
{}

// Common methods
void PhysicalObject::intersect(PhysicalObject::Ptr other, std::vector<Intersection>& intersections) const {
    border->intersect(other->border, intersections);
}

void PhysicalObject::update(double time) noexcept {
    position += speed * time;
}
