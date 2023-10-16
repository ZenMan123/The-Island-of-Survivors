#include "graphics_context.hpp"


//// GraphicsContext

// Constructors
GraphicsContext::GraphicsContext() {
}

// Singleton
GraphicsContext::Ptr GraphicsContext::GetInstance() {
    if (graphics_context_ == nullptr) {
        graphics_context_ = new GraphicsContext();
    }
    return graphics_context_;
}
