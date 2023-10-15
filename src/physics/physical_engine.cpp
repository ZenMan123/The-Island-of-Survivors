#include "physical_engine.hpp"


// Constructors
PhysicalEngine::PhysicalEngine() noexcept {
    context_ = PhysicalContext::GetInstance();
}

void PhysicalEngine::init() noexcept {
}

// Common functions
void PhysicalEngine::update(double time) {
    for (const auto& [id, object] : context_->movable_objects) {
        object->update(time);

        for (const auto& [intersect_id, intersect_object] : context_->movable_objects) {
            if (id == intersect_id) {
                continue;
            }

            object->intersect(intersect_object, intersectoins_buffer_);
            for (const auto& intersection : intersectoins_buffer_) {
                intersections_.push_back(ObjectsIntersection{.first = object, .second = intersect_object, .intersection = intersection});
            }
            intersectoins_buffer_.clear();
        }
    }
}

// Private functions
void PhysicalEngine::apply_intersections() noexcept {
    for (const auto& intersection : intersections_) {
        intersection.first->apply_intersection(intersection.intersection, intersection.second);
    }
    intersections_.clear();
}
