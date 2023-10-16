#pragma once

#include <common/math/vec2.hpp>


using RenderWindowPtr = std::shared_ptr<sf::RenderWindow>;


// Standart dpawable resource
class Resource {
public:
    using Ptr = std::shared_ptr<Resource>;

    // Common functions
    virtual void draw(RenderWindowPtr target, const Vec2& position, const Vec2& size) = 0;

    // Destructors
    virtual ~Resource();
};


// Dpawable resource with one color
class ColorResource : public Resource {
    sf::RectangleShape rectangle_;

public:
    using Ptr = std::shared_ptr<ColorResource>;
    
    // Constructors
    ColorResource(const sf::Color& color);

    // Common functions
    void draw(RenderWindowPtr target, const Vec2& position, const Vec2& size) override final;

    // Static functions
    template <typename ...Args>
    [[nodiscard]] static ColorResource::Ptr make(Args&&... args) {
        return std::make_shared<ColorResource>(std::forward<Args>(args)...);
    }
};
