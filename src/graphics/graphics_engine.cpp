#include "graphics_engine.hpp"


// Constructors
GraphicsEngine::GraphicsEngine() noexcept
    : context_(GraphicsContext::GetInstance())
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

void GraphicsEngine::folllow(PhysicalObject::Ptr object) noexcept {
    folllow_object_ = object;
}

void GraphicsEngine::update(double time) noexcept {
    if (folllow_object_) {
        camera.position = folllow_object_->position;
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
