#pragma once

#include "object_border.hpp"

#include <common/objects/follow_object.hpp>


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
class PhysicalObject : public AllowFollow {
    PhysicalObjectConfig object_config_;

public:
    using Ptr = std::shared_ptr<PhysicalObject>;

    Vec2 speed;
    Vec2 position;
    Vec2 strength;
    ObjectBorder::Ptr border;

    // Constructors
    PhysicalObject();

    void init(const PhysicalObjectConfig& object_config);

    // Getters
    virtual Vec2 get_position() const noexcept override;

    // Statistics
    [[nodiscard]] bool is_movable() const noexcept;

    // Common methods
    void intersect(const PhysicalObject::Ptr& other, std::vector<Intersection>& intersections) const;

    void apply_intersection(const Intersection& intersection, const PhysicalObject::Ptr& other) noexcept;

    void update_basic(double time) noexcept;

    void drop_state() noexcept;

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
