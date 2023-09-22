#include "graphics_context.hpp"


// Constructors
GraphicsContext::GraphicsContext() {
}

// Singleton
GraphicsContext* GraphicsContext::GetInstance() {
    if (graphics_context_ == nullptr) {
        graphics_context_ = new GraphicsContext();
    }
    return graphics_context_;
}
