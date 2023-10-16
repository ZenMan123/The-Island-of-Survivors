#include "resource.hpp"


//// Resource

// Destructors
Resource::~Resource() {
}


//// ColorResource

// Constructors
ColorResource::ColorResource(const sf::Color& color) {
    rectangle_.setFillColor(color);
}

// Common functions
void ColorResource::draw(RenderWindowPtr target, const Vec2& position, const Vec2& size) {
    ENSURE(target, RuntimeError, "invalid drawable target");
    CHECK(size.x >= 0 && size.y >= 0, "invalid resource size");

    rectangle_.setPosition(sf::Vector2f(position));
    rectangle_.setSize(sf::Vector2f(size));

    target->draw(rectangle_);
}
