#pragma once

#include <common/objects/follow_object.hpp>
#include <graphics/drawable_objects/resources/resource_interface.hpp>


// Camera that convert from game space to screen space
class Camera : public CanFollow {
    RenderWindowPtr target_;
    Vec2 position_;

    double width_ = 0.0;
    double height_ = 0.0;

public:
    // Constructors
    Camera() noexcept;

    Camera(RenderWindowPtr target, double width, const Vec2& position);

    // Setters
    void set_position(const Vec2& position) noexcept override final;

    // Getters
    [[nodiscard]] Vec2 get_position() const noexcept;

    [[nodiscard]] RenderWindowPtr get_target() const noexcept;

    // Common functions
    [[nodiscard]] Vec2 convert_point(const Vec2& point) const;

    [[nodiscard]] Vec2 convert_size(const Vec2& size) const;

    void update() noexcept;
};
