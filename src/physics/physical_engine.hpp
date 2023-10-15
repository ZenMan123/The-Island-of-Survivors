#pragma once

#include "physical_context.hpp"


// 2D graphics engine
class PhysicalEngine {
    PhysicalContext* context_;

public:
    // Constructors
    PhysicalEngine() noexcept;

    void Init() noexcept;

    // Common functions
    void update(double time) const;
};
