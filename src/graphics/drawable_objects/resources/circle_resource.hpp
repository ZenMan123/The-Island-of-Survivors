#pragma once

#include "resource_interface.hpp"


// Dpawable resource with one circle
class CircleResource : public Resource {
    sf::CircleShape circle_;

public:
    using Ptr = std::shared_ptr<CircleResource>;

    // Constructors
    CircleResource();

    CircleResource(const sf::Color& color);

    // Common functions
    [[nodiscard]] sf::CircleShape& mutable_circle() noexcept;

    void draw(RenderWindowPtr target, const Vec2& position, const Vec2& size) override final;

    // Static functions
    template <typename ...Args>
    [[nodiscard]] static CircleResource::Ptr make(Args&&... args) {
        return std::make_shared<CircleResource>(std::forward<Args>(args)...);
    }
};
