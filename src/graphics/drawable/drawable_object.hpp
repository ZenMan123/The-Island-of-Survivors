#pragma once

#include "resource.hpp"

#include <graphics/camera/camera.hpp>


// Common interface for all drawable objects
class DrawableObject {
    Resource::Ptr drawable_resource_;

protected:
    Vec2 size;

    // Protected functions
    void set_drawable_resource(Resource::Ptr resource) noexcept;

public:
    using Ptr = std::shared_ptr<DrawableObject>;

    Vec2 position;

    // Constructors
    DrawableObject(const Vec2& position, const Vec2& size) noexcept;

    DrawableObject(const Vec2& position, const Vec2& size, Resource::Ptr resource) noexcept;

    // Destructors
    virtual ~DrawableObject();

    // Setters
    void set_size(const Vec2& size) noexcept;

    // Getters
    [[nodiscard]] Vec2 get_size() const noexcept;
    
    // Common functions
    void draw(const Camera& camera) const;
};
