#pragma once

#include "resource_interface.hpp"


// Dpawable resource with one rectangle
class RectangleResource : public Resource {
    sf::RectangleShape rectangle_;

public:
    using Ptr = std::shared_ptr<RectangleResource>;

    // Constructors
    RectangleResource();

    RectangleResource(const sf::Color& color);

    // Common functions
    [[nodiscard]] sf::RectangleShape& mutable_rectangle() noexcept;

    void draw(RenderWindowPtr target, const Vec2& position, const Vec2& size) override final;

    // Static functions
    template <typename ...Args>
    [[nodiscard]] static RectangleResource::Ptr make(Args&&... args) {
        return std::make_shared<RectangleResource>(std::forward<Args>(args)...);
    }
};
