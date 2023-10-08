#include "graphics_engine.hpp"


// Constructors
GraphicsEngine::GraphicsEngine() noexcept = default;

void GraphicsEngine::Init(RenderWindowPtr target) noexcept {
    target_ = std::move(target);
}

// Common functions
void GraphicsEngine::draw() const {
    for (const auto& [id, object] : GraphicsContext::GetInstance()->drawable_objects) {
        object->draw(target_);
    }
}

// Static functions
RenderWindowPtr GraphicsEngine::create_window(const std::string& title, uint32_t style) {
    const auto& fullscreen_modes = sf::VideoMode::getFullscreenModes();

    if (!fullscreen_modes.empty()) {
        return std::make_shared<sf::RenderWindow>(fullscreen_modes[0], title, style);
    }

    return std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), title, style);
}
