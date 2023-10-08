#include "game.hpp"
#include <SFML/Window.hpp>

Game::Game() = default;

void Game::process_event(const sf::Event& event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            process_key_pressed_(event);
            break;

        case sf::Event::KeyReleased:
            process_key_released_(event);
            break;

        default:
            break;
    }
}

void Game::process_key_pressed_(const sf::Event& event) {

}

void Game::process_key_released_(const sf::Event& event) {

}