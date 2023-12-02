#pragma once

#include "drawable_object.hpp"


// Sprite can save and switch between multiple resources
class Sprite : public DrawableObject {
    std::vector<Resource::Ptr> resources_;

public:
    using Base = DrawableObject;
    using Ptr = std::shared_ptr<Sprite>;

    // Constructors
    Sprite() noexcept;

    void init(const Vec2& position, const Vec2& size) noexcept;

    // Common functions
    void set_resource_id(size_t id);

    // Updaters
    void insert_resource(Resource::Ptr resource);

    // Destructors
    virtual ~Sprite();

    // Static functions
    template <typename ...Args>
    [[nodiscard]] static Sprite::Ptr make(Args&&... args) {
        Sprite::Ptr object = std::make_shared<Sprite>();
        object->init(std::forward<Args>(args)...);
        return object;
    }
};
