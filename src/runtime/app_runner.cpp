#include <configuration/app_config.hpp>
#include "app_runner.hpp"
#include <SFML/Graphics.hpp>

AppRunner::AppRunner() = default;

void AppRunner::Init() {
    window_ = GraphicsEngine::create_window(app_config::APPLICATION_NAME,
                                            sf::Style::Default);
    game_.Init(window_);
}

void AppRunner::Draw() const {
    game_.Draw();
    window_->display();
}

void AppRunner::run() {
    sf::Event event;
    while (window_->isOpen()) {
        Draw();
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
