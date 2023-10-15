#include "physical_object.hpp"
//// PhysicalObjectConfig

// Constructors
PhysicalObjectConfig::PhysicalObjectConfig() noexcept {
}

PhysicalObjectConfig::PhysicalObjectConfig(double restitution) 
    : movable_(false)
    , weight(0.0)
    , restitution(restitution)
{
    ENSURE(restitution >= 0, InvalidArgument, "Restitution must be greater than zero");
}

PhysicalObjectConfig::PhysicalObjectConfig(double weight, double restitution) 
    : movable_(true)
    , weight(weight)
    , restitution(restitution)
{
    ENSURE(weight > 0, InvalidArgument, "Weight must be greater than zero");
    ENSURE(restitution >= 0, InvalidArgument, "Restitution must be greater than zero");
}

// Common methods
double PhysicalObjectConfig::get_reversed_weight() const noexcept {
    return movable_ ? 1.0 / weight : 0.0;
}

//// PhysicalObject

// Constructors
PhysicalObject::PhysicalObject() = default;

void PhysicalObject::init(PhysicalObjectConfig object_config) {
    object_config_ = object_config;
}

// Destructors
PhysicalObject::~PhysicalObject() = default;

// Common methods
void PhysicalObject::intersect(const PhysicalObject::Ptr& other, std::vector<Intersection>& intersections) const {
    border->intersect(other->border, intersections);
}

void PhysicalObject::update_basic(double time) noexcept {
    position += speed * time;
}

void PhysicalObject::apply_intersection(const Intersection& intersection, const PhysicalObject::Ptr& other) noexcept {
    Vec2 normal = intersection.direction.normalize();
    
    double projected_velocity = (other->speed - speed) * normal;
    if (projected_velocity > 0.0) {
        return;
    }

    double ratio = std::min(object_config_.restitution, other->object_config_.restitution);
    
    double this_weight = object_config_.get_reversed_weight();
    double other_weight = other->object_config_.get_reversed_weight();

    Vec2 impulse = (-(1.0 + ratio) * projected_velocity / (this_weight + other_weight)) * normal;

    speed -= impulse * this_weight;
    other->speed += impulse * other_weight;
}

