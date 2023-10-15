#pragma once

#include "physical_context.hpp"


// 2D graphics engine
class PhysicalEngine {
public:
    // Constructors
    PhysicalEngine() noexcept;

    void Init() noexcept;

    // Common functions
    void update() const;
};
