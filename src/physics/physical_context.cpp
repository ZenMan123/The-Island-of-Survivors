#include "physical_context.hpp"


//// PhysicalContext

// Constructors
PhysicalContext::PhysicalContext() {
}

// Singleton
PhysicalContext* PhysicalContext::GetInstance() {
    if (physical_context_ == nullptr) {
        physical_context_ = new PhysicalContext();
    }
    return physical_context_;
}
