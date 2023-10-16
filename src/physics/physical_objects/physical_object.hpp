#pragma once

#include "object_border.hpp"


struct PhysicalObjectConfig {
private:
    bool movable_ = false;
    double reversed_weight_ = 0.0;

public:
    double restitution = 0.0;

    // Constructors
    PhysicalObjectConfig() noexcept;

    PhysicalObjectConfig(double restitution);
    
    PhysicalObjectConfig(double weight, double restitution);

    // Common methods
    [[nodiscard]] bool is_movable() const noexcept;

    [[nodiscard]] double get_reversed_weight() const noexcept;
};


// Common interface for physical objects 
class PhysicalObject {
    PhysicalObjectConfig object_config_;

public:
    using Ptr = std::shared_ptr<PhysicalObject>;

    Vec2 speed;
    Vec2 position;
    ObjectBorder::Ptr border;

    // Constructors
    PhysicalObject();

    void init(const PhysicalObjectConfig& object_config);

    // Statistics
    [[nodiscard]] bool is_movable() const noexcept;

    // Common methods
    void intersect(const PhysicalObject::Ptr& other, std::vector<Intersection>& intersections) const;

    void apply_intersection(const Intersection& intersection, const PhysicalObject::Ptr& other) noexcept;

    void update_basic(double time) noexcept;

    // Destructors
    virtual ~PhysicalObject();

    // Static functions
    template <typename ...Args>
    [[nodiscard]] static PhysicalObject::Ptr make(Args&&... args) {
        PhysicalObject::Ptr object = std::make_shared<PhysicalObject>();
        object->init(std::forward<Args>(args)...);
        return object;
    }
};
