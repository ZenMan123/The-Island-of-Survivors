#pragma once

#include "graphics_context.hpp"


// 2D graphics engine
class GraphicsEngine {
    GraphicsContext::Ptr context_;

public:
    Camera camera;

    // Constructors
    GraphicsEngine() noexcept;

    void init(const Camera& camera) noexcept;

    // Common functions
    void draw() const;

    void update(double time) noexcept;

    // Static functions
    [[nodiscard]] static RenderWindowPtr create_window(const std::string& title, uint32_t style = sf::Style::None);
};
