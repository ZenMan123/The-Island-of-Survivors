#pragma once

#include <graphics/drawable_objects/drawable_object.hpp>
#include <physics/physical_objects/physical_object.hpp>


// Game object with drawable and physical parts
class GameObject {
    // Private functions
    void insert_into_context();

    size_t drawable_object_id_;
    size_t physical_object_id_;

    DrawableObject::Ptr drawable_object_;
    PhysicalObject::Ptr physical_object_;

public:
    using Ptr = std::shared_ptr<GameObject>;

    // Constructors
    GameObject(DrawableObject::Ptr drawable_object, PhysicalObject::Ptr physical_object);

    // Destructors
    ~GameObject();

    // Static functions
    template <typename ...Args>
    [[nodiscard]] static GameObject::Ptr make(Args&&... args) {
        return std::make_shared<GameObject>(std::forward<Args>(args)...);
    }
};
