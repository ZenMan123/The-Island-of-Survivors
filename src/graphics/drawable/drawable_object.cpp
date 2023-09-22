#include "drawable_object.hpp"


// Constructors
DrawableObject::DrawableObject(const Vec2& position, const Vec2& size, Resource::Ptr resource) noexcept
    : position(position)
    , size(size)
    , resource(std::move(resource))
{
    CHECK(size.x >= 0 && size.y >= 0, "invalid resource size");
}

// Setters
void DrawableObject::set_size(const Vec2& size) noexcept {
    CHECK(size.x >= 0 && size.y >= 0, "invalid resource size");
    this->size = size;
}

// Getters
Vec2 DrawableObject::get_size() const noexcept {
    return size;
}
    
// Common functions
void DrawableObject::draw(RenderWindowPtr target) const {
    resource->draw(target, position, size);
}
