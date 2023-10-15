#pragma once

#include "physical_objects/physical_object.hpp"

#include <common/utils/associative_storage.hpp>


// Graphic engine context
class PhysicalContext {
    inline static PhysicalContext* physical_context_ = nullptr;

    // Constructors
    PhysicalContext();

public:
    AssociativeStorage<PhysicalObject::Ptr> movable_objects;
    AssociativeStorage<PhysicalObject::Ptr> immovable_objects;

    // Singleton
    PhysicalContext(const PhysicalContext& other) = delete;
    PhysicalContext(PhysicalContext&& other) = delete;

    void operator=(const PhysicalContext&) = delete;
    void operator=(PhysicalContext&&) = delete;

    static PhysicalContext* GetInstance();
};
