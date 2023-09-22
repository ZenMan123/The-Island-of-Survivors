#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <memory>

#include <SFML/Graphics.hpp>


using RenderWindowPtr = std::shared_ptr<sf::RenderWindow>;


// Standart dpawable resource
class Resource {
public:
    using Ptr = std::unique_ptr<Resource>;

    virtual void draw(RenderWindowPtr target, const sf::FloatRect& location) = 0;
};


class ColorResource : public Resource {
    sf::RectangleShape rectangle_;

public:
    using Ptr = std::unique_ptr<ColorResource>;
    
    ColorResource(const sf::Color& color);

    void draw(RenderWindowPtr target, const sf::FloatRect& location) override final;
};
