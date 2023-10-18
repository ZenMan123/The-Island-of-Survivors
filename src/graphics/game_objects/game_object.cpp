#include "game_object.hpp"

#include <graphics/graphics_context.hpp>
#include <physics/physical_context.hpp>


//// GameObject

// Constructors
GameObject::GameObject(DrawableObject::Ptr drawable_object, PhysicalObject::Ptr physical_object)
    : drawable_object_(drawable_object)
    , physical_object_(physical_object)
{
    drawable_object_->follow(physical_object_);
    insert_into_context();
}

// Private functions
void GameObject::insert_into_context() {
    if (drawable_object_) {
        drawable_object_id_ = GraphicsContext::GetInstance()->drawable_objects.insert(drawable_object_);
    }
    if (physical_object_) {
        physical_object_id_ = PhysicalContext::GetInstance()->physical_objects.insert(physical_object_);
    }
}

// Destructors
GameObject::~GameObject() {
    if (drawable_object_) {
        GraphicsContext::GetInstance()->drawable_objects.erase(drawable_object_id_);
    }
    if (physical_object_) {
        PhysicalContext::GetInstance()->physical_objects.erase(physical_object_id_);
    }
}
