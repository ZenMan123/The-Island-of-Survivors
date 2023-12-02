#pragma once

#include <common/math/vec2.hpp>


using RenderWindowPtr = std::shared_ptr<sf::RenderWindow>;


// Standart dpawable resource interface
class Resource {
    Vec2 offset_;

    double rotation_ = 0.0;

protected:
    // Protected functions
    void validate_draw(RenderWindowPtr target, const Vec2& position, const Vec2& size);

public:
    using Ptr = std::shared_ptr<Resource>;

    // Setters
    void set_offset(const Vec2& offset) noexcept;

    void set_rotation(double rotation) noexcept;

    // Getters
    [[nodiscard]] Vec2 get_relative_offset() const noexcept;

    [[nodiscard]] Vec2 get_offset(const Vec2& size) const noexcept;

    [[nodiscard]] double get_rotation() const noexcept;

    // Common functions
    virtual void draw(RenderWindowPtr target, const Vec2& position, const Vec2& size) = 0;

    // Destructors
    virtual ~Resource();
};
