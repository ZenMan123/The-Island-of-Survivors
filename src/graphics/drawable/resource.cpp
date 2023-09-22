#include "resource.hpp"


// ColorResource
ColorResource::ColorResource(const sf::Color& color) {
    rectangle_.setFillColor(color);
}

void ColorResource::draw(RenderWindowPtr target, const sf::FloatRect& location) {
    rectangle_.setPosition(location.getPosition());
    rectangle_.setSize(location.getSize());

    target->draw(rectangle_);
}
