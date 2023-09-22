#include "graphics_engine.hpp"
#include "common/utils/functions.hpp"
#include <stdint.h>


// Constructors
GraphicsEngine::GraphicsEngine(RenderWindowPtr target) noexcept
    : target_(std::move(target))
{}

// Common functions
void GraphicsEngine::draw() const {
    for (const auto& [id, object] : GraphicsContext::GetInstance()->drawable_objects) {
        object->draw(target_);
    }
}

// Static functions
RenderWindowPtr GraphicsEngine::create_window(const std::string& title, uint32_t style) {
    const auto& fullscreen_modes = sf::VideoMode::getFullscreenModes();
    ENSURE(!fullscreen_modes.empty(), RuntimeError, "fullscreen wideo modes are not found");

    return std::make_shared<sf::RenderWindow>(fullscreen_modes[0], title, style);
}
