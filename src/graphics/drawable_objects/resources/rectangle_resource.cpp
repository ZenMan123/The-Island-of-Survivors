#include "rectangle_resource.hpp"


//// RectangleResource

// Constructors
RectangleResource::RectangleResource() {
}

RectangleResource::RectangleResource(const sf::Color& color) {
    rectangle_.setFillColor(color);
}

// Common functions
sf::RectangleShape& RectangleResource::mutable_rectangle() noexcept {
    return rectangle_;
}

void RectangleResource::draw(RenderWindowPtr target, const Vec2& position, const Vec2& size) {
    validate_draw(target, position, size);

    rectangle_.setOrigin(sf::Vector2f(get_offset(size)));
    rectangle_.setSize(sf::Vector2f(size));
    rectangle_.setPosition(sf::Vector2f(position));
    rectangle_.setRotation(radians_to_degrees(get_rotation()));

    target->draw(rectangle_);
}
