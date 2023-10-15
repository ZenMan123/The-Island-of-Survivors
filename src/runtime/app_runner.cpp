#include <configuration/app_config.hpp>
#include "app_runner.hpp"
#include <SFML/Graphics.hpp>

AppRunner::AppRunner() = default;

void AppRunner::init() {
    window_ = GraphicsEngine::create_window(app_config::APPLICATION_NAME,
                                            sf::Style::Default);
    game_.init(window_);
}

void AppRunner::draw() const {
    window_->clear();
    game_.draw();
    window_->display();
}

void AppRunner::update(double time) {
    game_.update(time);
}

void AppRunner::run() {
    sf::Event event;
    sf::Clock clock;

    while (window_->isOpen()) {
        update(clock.restart().asSeconds());
        draw();
        while (window_->pollEvent(event)) {
            game_.process_event(event);
            switch (event.type) {
                case sf::Event::Closed:
                    window_->close();
                    break;
                default:
                    break;
            }
        }
    }
}
