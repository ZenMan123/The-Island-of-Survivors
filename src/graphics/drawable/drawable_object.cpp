#include "drawable_object.hpp"


//// DrawableObject

// Constructors
DrawableObject::DrawableObject() noexcept {
}

void DrawableObject::init(const Vec2& position, const Vec2& size, Resource::Ptr resource) noexcept {
    CHECK(size.x >= 0 && size.y >= 0, "invalid drawable object size");

    this->drawable_resource_ = std::move(resource);
    this->size = size;
    this->position = position;
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
void DrawableObject::draw(const Camera& camera) const {
    ENSURE(drawable_resource_, RuntimeError, "drawable object are not initialized");

    drawable_resource_->draw(
        camera.get_target(),
        camera.convert_point(position),
        camera.convert_size(size)
    );
}

void DrawableObject::follow(PhysicalObject::Ptr object) noexcept {
    follow_object_ = object;
}

void DrawableObject::update(double time) noexcept {
    if (follow_object_) {
        position = follow_object_->position;
    }
}

// Protected functions
void DrawableObject::set_drawable_resource(Resource::Ptr resource) noexcept {
    drawable_resource_ = std::move(resource);
}

// Destructors
DrawableObject::~DrawableObject() {
}
