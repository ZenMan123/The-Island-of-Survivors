#pragma once

#include <graphics/drawable/resource.hpp>


class Camera {
    RenderWindowPtr target_;
    
    double width_ = 0.0;
    double height_ = 0.0;

public:
    Vec2 position;

    // Constructors
    Camera() noexcept;

    Camera(RenderWindowPtr target, double width, const Vec2& position);

    // Getters
    RenderWindowPtr get_target() const noexcept;

    // Common functions
    Vec2 convert_point(const Vec2& point) const noexcept;

    Vec2 convert_size(const Vec2& size) const noexcept;
};
