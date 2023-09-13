#pragma once

#include <memory>

#include <SFML/Graphics.hpp>


// Standart dpawable resource
class Resource {
public:
    using Ptr = std::unique_ptr<Resource>;
};


class ColorResource : public Resource {
    sf::Color color_;

public:
    using Ptr = std::unique_ptr<ColorResource>;
    
    ColorResource(const sf::Color& color);
};
