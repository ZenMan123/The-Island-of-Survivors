#include <graphics/graphics_context.hpp>

#include <iostream>


int main() {
    std::cout << "Hello world!\n";

    Resource::Ptr resource = std::make_unique<ColorResource>(sf::Color(255, 0, 0));

    Vec2 position(0.0);
    Vec2 size(100.0);
    DrawableObject object(position, size, std::move(resource));

    RenderWindowPtr window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Hello world window");
    while (window->isOpen()) {
        for (sf::Event event; window->pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear(sf::Color::Black);

        object.draw(window);

        window->display();
    }

    return 0;
}
