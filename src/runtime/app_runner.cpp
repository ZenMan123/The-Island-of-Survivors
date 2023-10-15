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

void AppRunner::Update(double time) {
    game_.Update(time);
}

void AppRunner::run() {
    sf::Event event;
    sf::Clock clock;

    while (window_->isOpen()) {
        Update(clock.restart().asSeconds());
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
