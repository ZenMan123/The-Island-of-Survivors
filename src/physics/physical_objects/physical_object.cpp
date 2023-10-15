#include "physical_object.hpp"


// Constructors
PhysicalObject::PhysicalObject(const Vec2& position, double restitution)
    : movable_(false)
    , reversed_weight_(0.0)
    , restitution_(restitution)
    , position(position)
{
    ENSURE(restitution_ >= 0, InvalidArgument, "Restitution must be greater than zero");
}

PhysicalObject::PhysicalObject(const Vec2& position, double weight, double restitution)
    : movable_(true)
    , reversed_weight_(1.0 / weight)
    , restitution_(restitution)
    , position(position)
{
    ENSURE(reversed_weight_ >= 0, InvalidArgument, "Weight must be greater than zero");
    ENSURE(restitution_ >= 0, InvalidArgument, "Restitution must be greater than zero");
}

// Common methods
void PhysicalObject::intersect(PhysicalObject::Ptr other, std::vector<Intersection>& intersections) const {
    border->intersect(other->border, intersections);
}

void PhysicalObject::update(double time) noexcept {
    if (!movable_) {
        return;
    }
    
    position += speed * time;
}

void PhysicalObject::apply_intersection(const Intersection& intersection, PhysicalObject::Ptr other) noexcept {
    Vec2 normal = intersection.direction.normalize();
    
    double projected_velocity = (other->speed - speed) * normal;
    if (projected_velocity > 0.0) {
        return;
    }

    double ratio = std::min(restitution_, other->restitution_);
    
    Vec2 impulse = (-(1.0 + ratio) * projected_velocity / (reversed_weight_ + other->reversed_weight_)) * normal;

    speed -= impulse * reversed_weight_;
    other->speed += impulse * reversed_weight_;
}
