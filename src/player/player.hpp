#include <physics/physical_objects/physical_object.hpp>

class Player : public PhysicalObject {
    using Base = PhysicalObject;

public:
    void StartMoveLeft() {
        Base::speed += Vec2(-5.0, 0.0);
    }

    void StartMoveRight() {
        Base::speed += Vec2(5.0, 0.0);
    }

    void Update(double time) {
        Base::update(time);
    }
};