#include "drawable_object.hpp"


// Constructors
DrawableObject::DrawableObject(const Vec2& position, const Vec2& size) noexcept
    : position(position)
    , size(size)
{
    CHECK(size.x >= 0 && size.y >= 0, "invalid resource size");
}

DrawableObject::DrawableObject(const Vec2& position, const Vec2& size, Resource::Ptr resource) noexcept
    : position(position)
    , size(size)
    , drawable_resource_(std::move(resource))
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
    drawable_resource_->draw(target, position, size);
}

// Protected functions
void DrawableObject::set_drawable_resource(Resource::Ptr resource) noexcept {
    drawable_resource_ = std::move(resource);
}
