#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    std::cout << "Hello world!\n";

    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello world window");
    while (window.isOpen()) {
        for (sf::Event event; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}
