#pragma once

#include "graphics_context.hpp"

#include <string>


// 2D graphics engine
class GraphicsEngine {
    RenderWindowPtr target_;

public:
    // Constructors
    GraphicsEngine() noexcept;

    void Init(RenderWindowPtr target) noexcept;

    // Common functions
    void draw() const;

    // Static functions
    static RenderWindowPtr create_window(const std::string& title, uint32_t style = sf::Style::None);
};
