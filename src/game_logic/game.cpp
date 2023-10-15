#include "game.hpp"
#include <SFML/Window.hpp>

Game::Game() = default;

void Game::init(RenderWindowPtr window) {
    window_ = std::move(window);
    graphics_engine_.init(Camera(window_, 10, {0, 0}));
}

void Game::draw() const {
    Resource::Ptr resource = std::make_unique<ColorResource>(sf::Color(255, 0, 0));

    Vec2 position(0.0);
    Vec2 size(100.0);
    DrawableObject::Ptr object = std::make_shared<DrawableObject>(position,
                                                                  size,
                                                                  std::move(resource));

    GraphicsContext::GetInstance()->drawable_objects.insert(std::move(object));

    graphics_engine_.draw();
}

void Game::Update(double time) {

}

void Game::process_event(const sf::Event& event) {
    switch (event.type) {
        main_player_.process_event(event);

        default:
            break;
    }
}
