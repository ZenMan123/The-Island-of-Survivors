#pragma once

#include "drawable_object.hpp"


class Sprite : public DrawableObject {
    std::vector<Resource::Ptr> resources_;

public:
    using Base = DrawableObject;

    // Constructors
    Sprite(const Vec2& position, const Vec2& size) noexcept;

    // Common functions
    void set_resource_id(size_t id);

    // Updaters
    void insert_resource(Resource::Ptr resource);
};
