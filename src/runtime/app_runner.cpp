#include <configuration/app_config.hpp>
#include "app_runner.hpp"
#include <SFML/Graphics.hpp>

AppRunner::AppRunner() = default;

void AppRunner::run() {
    sf::Event event;
    while (window_.pollEvent(event)) {
        switch (event.type) {
            default:
                game_.process_event(event);

            case sf::Event::Closed:
                window_.close();
                break;
        }
    }
}
