#include "camera.hpp"


//// Camera

// Constructors
Camera::Camera() noexcept {
}

Camera::Camera(RenderWindowPtr target, double width, const Vec2& position)
    : target_(std::move(target))
    , width_(width)
    , position_(position)
{
    ENSURE(target_, InvalidArgument, "invalid drawable target");
    CHECK(width_ > 0.0, "width must be greater than zero");

    height_ = double(target_->getSize().y) * width / double(target_->getSize().x);
}

// Setters
void Camera::set_position(const Vec2& position) noexcept {
    position_ = position;
}

// Getters
Vec2 Camera::get_position() const noexcept {
    return position_;
}

RenderWindowPtr Camera::get_target() const noexcept {
    return target_;
}

// Common functions
Vec2 Camera::convert_point(const Vec2& point) const {
    ENSURE(target_, RuntimeError, "camera are not initialized");

    Vec2 delta = point - position_;

    return Vec2(
        double(target_->getSize().x) * (0.5 + delta.x / width_),
        double(target_->getSize().y) * (0.5 - delta.y / height_)
    );
}

Vec2 Camera::convert_size(const Vec2& size) const {
    ENSURE(target_, RuntimeError, "camera are not initialized");

    return Vec2(
        double(target_->getSize().x) * size.x / width_,
        double(target_->getSize().y) * size.y / height_
    );
}

void Camera::update() noexcept {
    follow_update();
}
