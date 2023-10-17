#include "game_map.h"

GameMap::GameMap() = default;

void GameMap::init() {
    auto ph_obj = PhysicalObject::make(PhysicalObjectConfig(
        1.0, 1.0
    ));
    ph_obj->position = Vec2(2, 0.5);
    ph_obj->border = BoxBorder::make(Vec2(0.0, -1.0), Vec2(1.0, 0.0));

    auto dr_obj = DrawableObject::make(ph_obj->position, Vec2(1.0), ColorResource::make(sf::Color::Red));
    dr_obj->follow(ph_obj);

    PhysicalContext::GetInstance()->physical_objects.insert(ph_obj);
    GraphicsContext::GetInstance()->drawable_objects.insert(dr_obj);

    objects_.push_back(dr_obj);
}

void GameMap::update(double time) {
    for (const auto& object : objects_) {
        object->update(time);
    }
}
