#include "sprite.hpp"


// Constructors
Sprite::Sprite(const Vec2& position, const Vec2& size) noexcept
    : Base(position, size)
{}

// Common functions
void Sprite::set_resource_id(size_t id) {
    ENSURE(id < resources_.size(), OutOfRange, "Invalid resource id");
    set_drawable_resource(resources_[id]);
}

// Updaters
void Sprite::insert_resource(Resource::Ptr resource) {
    if (resources_.empty()) {
        set_drawable_resource(resource);
    }

    resources_.push_back(resource);
}
