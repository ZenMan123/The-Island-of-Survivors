#pragma once

#include "graphics_context.hpp"


// 2D graphics engine
class GraphicsEngine {
    Camera camera_;
    
    GraphicsContext* context_ = nullptr;

public:
    // Constructors
    GraphicsEngine() noexcept;

    void init(const Camera& camera) noexcept;

    // Common functions
    void draw() const;

    // Static functions
    static RenderWindowPtr create_window(const std::string& title, uint32_t style = sf::Style::None);
};
