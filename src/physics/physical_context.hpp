#pragma once

#include "physical_objects/physical_object.hpp"

#include <common/utils/associative_storage.hpp>


// Physical engine context
class PhysicalContext {
public:
    using Ptr = PhysicalContext*;

    AssociativeStorage<PhysicalObject::Ptr> physical_objects;

    // Singleton
    PhysicalContext(const PhysicalContext& other) = delete;
    PhysicalContext(PhysicalContext&& other) = delete;

    void operator=(const PhysicalContext&) = delete;
    void operator=(PhysicalContext&&) = delete;

    static PhysicalContext* GetInstance();

private:
    inline static PhysicalContext::Ptr physical_context_ = nullptr;

    // Constructors
    PhysicalContext();
};
