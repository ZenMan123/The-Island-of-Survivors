#pragma once

#include "object_border.hpp"


struct PhysicalObjectConfig {
private:
    bool movable_ = false;

public:
    double weight;
    double restitution;

    // Constructors
    PhysicalObjectConfig() noexcept;

    PhysicalObjectConfig(double restitution);
    
    PhysicalObjectConfig(double weight, double restitution);

    // Common methods
    double get_reversed_weight() const noexcept;
};


// Common interface for physical objects 
class PhysicalObject {
    PhysicalObjectConfig object_config_;

public:
    using Ptr = std::shared_ptr<PhysicalObject>;

    Vec2 speed = Vec2(0.0);

    Vec2 position;
    ObjectBorder::Ptr border;

    // Constructors
    PhysicalObject();

    // Destructors
    virtual ~PhysicalObject();

    void init(PhysicalObjectConfig object_config);

    // Common methods
    void intersect(const PhysicalObject::Ptr& other, std::vector<Intersection>& intersections) const;

    void update_basic(double time) noexcept;

    void apply_intersection(const Intersection& intersection, const PhysicalObject::Ptr& other) noexcept;
};
