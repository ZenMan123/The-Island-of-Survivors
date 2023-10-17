#pragma once

#include <graphics/drawable/drawable_object.hpp>


// Game object with drawable and physical parts
class GameObject {
    void insert_into_context();

public:
    DrawableObject::Ptr drawable_object;
    PhysicalObject::Ptr physical_object;

    // Constructors
    GameObject(DrawableObject::Ptr drawable_object, PhysicalObject::Ptr physical_object);
};
