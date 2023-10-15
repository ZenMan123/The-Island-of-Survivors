#include "physical_engine.hpp"


// Constructors
PhysicalEngine::PhysicalEngine() noexcept {
    context_ = PhysicalContext::GetInstance();
}

void PhysicalEngine::Init() noexcept {
}

// Common functions
void PhysicalEngine::update(double time) const {
    for (const auto& [id, object] : context_->movable_objects) {
        object->update(time);
    }
}
