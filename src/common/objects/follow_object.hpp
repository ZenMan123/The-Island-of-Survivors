#pragma once

#include <common/math/vec2.hpp>


// Interface for objects which can be followed
class AllowFollow {
public:
    using Ptr = std::shared_ptr<AllowFollow>;

    // Getters
    virtual Vec2 get_position() const noexcept = 0;

    // Destructors
    virtual ~AllowFollow();
};


// Interface for objects which can follow
class CanFollow {
    AllowFollow::Ptr follow_object_;
    Vec2 follow_offset_;

protected:
    // Protected functions
    void follow_update() noexcept;

public:
    // Setters
    void set_follow_object(AllowFollow::Ptr object) noexcept;

    void set_follow_offset(const Vec2& offset) noexcept;

    virtual void set_position(const Vec2& position) noexcept = 0;

    // Getters
    [[nodiscard]] AllowFollow::Ptr get_follow_object() const noexcept;

    [[nodiscard]] Vec2 get_follow_offset() const noexcept;

    // Common functions
    void follow(AllowFollow::Ptr object, const Vec2& offset = Vec2()) noexcept;

    void unfollow() noexcept;

    // Destructors
    virtual ~CanFollow();
};
