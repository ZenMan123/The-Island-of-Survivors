#include <graphics/drawable/resource.hpp>

#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    std::cout << "Hello world!\n";

    ColorResource resource(sf::Color(255, 0, 0));

    RenderWindowPtr window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Hello world window");
    while (window->isOpen()) {
        for (sf::Event event; window->pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear(sf::Color::Black);

        sf::FloatRect position(
            0.0, 0.0, 100.0, 100.0
        );

        resource.draw(window, position);

        window->display();
    }

    return 0;
}
