#include "resource.hpp"


// ColorResource

// Constructors
ColorResource::ColorResource(const sf::Color& color) {
    rectangle_.setFillColor(color);
}

// Common functions
void ColorResource::draw(RenderWindowPtr target, const sf::FloatRect& location) {
    rectangle_.setPosition(location.getPosition());
    rectangle_.setSize(location.getSize());

    target->draw(rectangle_);
}
