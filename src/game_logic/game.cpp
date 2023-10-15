#include "game.hpp"
#include <SFML/Window.hpp>

Game::Game() = default;

void Game::init(RenderWindowPtr window) {
    window_ = std::move(window);

    main_player_ptr_ = std::make_shared<Player>();
    main_player_ptr_->init();
    PhysicalContext::GetInstance()->movable_objects.insert(main_player_ptr_);
    graphics_engine_.init(Camera(window_, 10, {0, 0}));
    physics_engine_.init();
}

void Game::draw() const {
    graphics_engine_.draw();
}

void Game::update(double time) {
    physics_engine_.update(time);
}

void Game::process_event(const sf::Event& event) {
    main_player_ptr_->process_event(event);
    switch (event.type) {
        default:
            break;
    }
}
