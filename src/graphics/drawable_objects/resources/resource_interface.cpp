#include "resource_interface.hpp"


//// Resource

// Protected functions
void Resource::validate_draw(RenderWindowPtr target, const Vec2&, const Vec2& size) {
    ENSURE(target, RuntimeError, "invalid drawable target");
    CHECK(size.x >= 0 && size.y >= 0, "invalid resource size");
}

// Setters
void Resource::set_offset(const Vec2& offset) noexcept {
    offset_ = offset;
}

void Resource::set_rotation(double rotation) noexcept {
    rotation_ = rotation;
}

// Getters
Vec2 Resource::get_relative_offset() const noexcept {
    return offset_;
}

Vec2 Resource::get_offset(const Vec2& size) const noexcept {
    return offset_.multiply(size);
}

double Resource::get_rotation() const noexcept {
    return rotation_;
}

// Destructors
Resource::~Resource() {
}
