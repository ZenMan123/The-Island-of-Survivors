#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <memory>

#include <SFML/Graphics.hpp>


using RenderWindowPtr = std::shared_ptr<sf::RenderWindow>;


// Standart dpawable resource
class Resource {
public:
    using Ptr = std::unique_ptr<Resource>;

    // Common functions
    virtual void draw(RenderWindowPtr target, const sf::FloatRect& location) = 0;
};


// Dpawable resource with one color
class ColorResource : public Resource {
    sf::RectangleShape rectangle_;

public:
    using Ptr = std::unique_ptr<ColorResource>;
    
    // Constructors
    ColorResource(const sf::Color& color);

    // Common functions
    void draw(RenderWindowPtr target, const sf::FloatRect& location) override final;
};
