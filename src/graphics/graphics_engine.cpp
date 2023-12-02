#include "graphics_engine.hpp"


//// GraphicsEngine

// Constructors
GraphicsEngine::GraphicsEngine() noexcept
    : context_(std::move(GraphicsContext::GetInstance()))
{}

void GraphicsEngine::init(const Camera& camera) noexcept {
    this->camera = camera;
}

// Common functions
void GraphicsEngine::draw() const {
    for (const auto& [id, object] : context_->drawable_objects) {
        object->draw(camera);
    }
}

void GraphicsEngine::update(double time) noexcept {
    camera.update();
    for (const auto& [id, object] : context_->drawable_objects) {
        object->update(time);
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
