#pragma once

#include <graphics/drawable/resource.hpp>


// Camera that convert from game space to screen space
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
    [[nodiscard]] RenderWindowPtr get_target() const noexcept;

    // Common functions
    [[nodiscard]] Vec2 convert_point(const Vec2& point) const;

    [[nodiscard]] Vec2 convert_size(const Vec2& size) const;
};
