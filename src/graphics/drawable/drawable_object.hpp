#pragma once

#include "resource.hpp"


// Common interface for all drawable objects
class DrawableObject {
protected:
    Vec2 size;

public:
    using Ptr = std::shared_ptr<DrawableObject>;

    Vec2 position;
    Resource::Ptr resource;

    // Constructors
    DrawableObject(const Vec2& position, const Vec2& size, Resource::Ptr resource) noexcept;

    // Setters
    void set_size(const Vec2& size) noexcept;

    // Getters
    Vec2 get_size() const noexcept;
    
    // Common functions
    virtual void draw(RenderWindowPtr target) const;
};
