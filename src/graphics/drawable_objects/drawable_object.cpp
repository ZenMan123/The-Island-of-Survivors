#include "drawable_object.hpp"


//// DrawableObject

// Constructors
DrawableObject::DrawableObject() noexcept {
}

void DrawableObject::init(const Vec2& size, Resource::Ptr resource) noexcept {
    CHECK(size.x >= 0 && size.y >= 0, "invalid drawable object size");

    drawable_resource_ = std::move(resource);
    this->size = size;
}

void DrawableObject::init(const Vec2& position, const Vec2& size, Resource::Ptr resource) noexcept {
    CHECK(size.x >= 0 && size.y >= 0, "invalid drawable object size");

    drawable_resource_ = std::move(resource);
    this->size = size;
    this->position = position;
}

// Setters
void DrawableObject::set_position(const Vec2& position) noexcept {
    this->position = position;
}

void DrawableObject::set_size(const Vec2& size) noexcept {
    CHECK(size.x >= 0 && size.y >= 0, "invalid resource size");
    this->size = size;
}

void DrawableObject::set_drawable_resource(Resource::Ptr resource) noexcept {
    drawable_resource_ = std::move(resource);
}

// Getters
Vec2 DrawableObject::get_size() const noexcept {
    return size;
}

// Common functions
void DrawableObject::draw(const Camera& camera) const {
    ENSURE(drawable_resource_, RuntimeError, "drawable object are not initialized");

    drawable_resource_->draw(
        camera.get_target(),
        camera.convert_point(position),
        camera.convert_size(size)
    );
}

void DrawableObject::update(double time) noexcept {
    follow_update();
}

// Destructors
DrawableObject::~DrawableObject() {
}
