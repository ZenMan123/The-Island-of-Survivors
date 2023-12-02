#include "circle_resource.hpp"


//// CircleResource

// Constructors
CircleResource::CircleResource() {
}

CircleResource::CircleResource(const sf::Color& color) {
    circle_.setFillColor(color);
    circle_.setRadius(1.0);
}

// Common functions
sf::CircleShape& CircleResource::mutable_circle() noexcept {
    return circle_;
}

void CircleResource::draw(RenderWindowPtr target, const Vec2& position, const Vec2& size) {
    validate_draw(target, position, size);

    circle_.setOrigin(sf::Vector2f(get_offset(size)));
    circle_.setScale(sf::Vector2f(size));
    circle_.setPosition(sf::Vector2f(position));
    circle_.setRotation(radians_to_degrees(get_rotation()));

    target->draw(circle_);
}