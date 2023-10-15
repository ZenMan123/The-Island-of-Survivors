#include "camera.hpp"


// Constructors
Camera::Camera() noexcept {
}

Camera::Camera(RenderWindowPtr target, double width, const Vec2& position)
    : target_(std::move(target))
    , width_(width)
    , height_(double(target->getSize().y) * width / double(target->getSize().x))
    , position(position)
{
    ENSURE(width_ > 0.0, InvalidArgument, "Width must be greater than zero");
}

// Getters
RenderWindowPtr Camera::get_target() const noexcept {
    return target_;
}

// Common functions
Vec2 Camera::convert_point(const Vec2& point) const noexcept {
    Vec2 delta = point - position;

    return Vec2(
        double(target_->getSize().x) * (0.5 + delta.x / width_),
        double(target_->getSize().y) * (0.5 - delta.y / height_)
    );
}

Vec2 Camera::convert_size(const Vec2& size) const noexcept {
    return Vec2(
        double(target_->getSize().x) * size.x / width_,
        double(target_->getSize().y) * size.y / height_
    );
}
