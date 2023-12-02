#include "game_map.hpp"
#include "graphics/drawable_objects/resources/rectangle_resource.hpp"

#include <iostream>

GameMap::GameMap() = default;

std::vector<std::string> load_field() {
    std::string filename = "../resources/game_field/basic_field.txt";
    std::ifstream fin(filename);

    std::vector<std::string> res;
    std::string tmp;
    while (getline(fin, tmp)) {
        res.push_back(tmp);
    }
    return res;
}

GameObject::Ptr MakeUsualBlock(int i, int j) {
    auto ph_obj = PhysicalObject::make(PhysicalObjectConfig(1.0));
    ph_obj->position = Vec2(j, i);
    ph_obj->border = BoxBorder::make(Vec2(0.0, -1.0), Vec2(1.0, 0.0));

    auto dr_obj = DrawableObject::make(ph_obj->position, Vec2(1.0),
                                       RectangleResource::make(sf::Color::Red));
    return GameObject::make(dr_obj, ph_obj);
}

GameObject::Ptr MakeMovableBlock(int i, int j) {
    auto ph_obj = PhysicalObject::make(PhysicalObjectConfig(1.0, 1.0));
    ph_obj->position = Vec2(j, i);
    ph_obj->border = BoxBorder::make(Vec2(0.0, -1.0), Vec2(1.0, 0.0));

    auto dr_obj = DrawableObject::make(ph_obj->position, Vec2(1.0),
                                       RectangleResource::make(sf::Color::Blue));
    return GameObject::make(dr_obj, ph_obj);
}

void GameMap::init() {
    auto field = load_field();
    for (int i = 0; i < field.size(); i++) {
        for (int j = 0; j < field[i].size(); j++) {
            if (field[i][j] == '.') {
                continue;
            }
            objects_.push_back(MakeUsualBlock(i, j));
        }
    }
    objects_.push_back(MakeMovableBlock(1, 2));
}

void GameMap::update(double time) {}
