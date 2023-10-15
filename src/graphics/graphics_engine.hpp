#pragma once

#include "graphics_context.hpp"

#include <physics/physical_objects/physical_object.hpp>


// 2D graphics engine
class GraphicsEngine {
    GraphicsContext* context_ = nullptr;
    PhysicalObject::Ptr folllow_object_ = nullptr;

public:
    Camera camera;

    // Constructors
    GraphicsEngine() noexcept;

    void init(const Camera& camera) noexcept;

    // Common functions
    void draw() const;

    void folllow(PhysicalObject::Ptr object) noexcept;

    void update(double time) noexcept;

    // Static functions
    static RenderWindowPtr create_window(const std::string& title, uint32_t style = sf::Style::None);
};
