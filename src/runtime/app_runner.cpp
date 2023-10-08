#include "app_runner.hpp"
#include <SFML/Graphics.hpp>

AppRunner::AppRunner() = default;

void AppRunner::run_game() {
    sf::Event event;
    while (window_.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window_.close();
                break;

            case sf::Event::KeyPressed:
                
        }

        if (event.type == sf::Event::KeyPressed) {

        }
    }
}