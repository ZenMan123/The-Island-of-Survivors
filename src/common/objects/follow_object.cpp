#include "follow_object.hpp"


//// AllowFollow

// Destructors
AllowFollow::~AllowFollow() {
}


//// CanFollow

// Setters
void CanFollow::set_follow_object(AllowFollow::Ptr object) noexcept {
    follow_object_ = std::move(object);
}

void CanFollow::set_follow_offset(const Vec2& offset) noexcept {
    follow_offset_ = offset;
}

// Getters
AllowFollow::Ptr CanFollow::get_follow_object() const noexcept {
    return follow_object_;
}

Vec2 CanFollow::get_follow_offset() const noexcept {
    return follow_offset_;
}

// Common functions
void CanFollow::follow(AllowFollow::Ptr object, const Vec2& offset) noexcept {
    follow_object_ = std::move(object);
    follow_offset_ = offset;
}

void CanFollow::unfollow() noexcept {
    follow_object_ = nullptr;
}

// Protected functions
void CanFollow::follow_update() noexcept {
    if (follow_object_) {
        set_position(follow_object_->get_position() + follow_offset_);
    }
}

// Destructors
CanFollow::~CanFollow() {
}
