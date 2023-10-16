#include "sprite.hpp"


//// Sprite

// Constructors
Sprite::Sprite() noexcept : Base() {
}

void Sprite::init(const Vec2& position, const Vec2& size) noexcept {
    CHECK(size.x >= 0 && size.y >= 0, "invalid sprite size");

    this->position = position;
    this->size = size;
}

// Common functions
void Sprite::set_resource_id(size_t id) {
    ENSURE(id < resources_.size(), OutOfRange, "invalid resource id");
    set_drawable_resource(resources_[id]);
}

// Updaters
void Sprite::insert_resource(Resource::Ptr resource) {
    if (resources_.empty()) {
        set_drawable_resource(resource);
    }

    resources_.push_back(std::move(resource));
}

// Destructors
Sprite::~Sprite() {
}
