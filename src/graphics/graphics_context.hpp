#pragma once

#include "drawable/drawable_object.hpp"

#include <common/utils/associative_storage.hpp>


// Graphic engine context
class GraphicsContext {
    inline static GraphicsContext* graphics_context_ = nullptr;

    // Constructors
    GraphicsContext();

public:
    AssociativeStorage<DrawableObject::Ptr> drawable_objects;

    // Singleton
    GraphicsContext(const GraphicsContext& other) = delete;
    GraphicsContext(GraphicsContext&& other) = delete;

    void operator=(const GraphicsContext&) = delete;
    void operator=(GraphicsContext&&) = delete;

    static GraphicsContext* GetInstance();
};
