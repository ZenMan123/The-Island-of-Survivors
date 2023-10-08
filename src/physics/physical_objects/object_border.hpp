#pragma once

#include <common/math/vec2.hpp>


struct Intersection {
    double penetration;
    Vec2 direction;
};


struct Edge {
    Vec2 start;
    Vec2 end;

    struct Intersection {
        uint8_t number_intersections;

        bool penetrate[2];
        Vec2 intersections[2];
    };
};


// Physical object border interface
class ObjectBorder {
    Vec2 left_bottom_;
    Vec2 right_top_;

    bool has_border_ = false;
    
    bool is_intersect(const ObjectBorder& other) const noexcept;

public:
    // Constructors
    ObjectBorder() noexcept;

    ObjectBorder(const Vec2& left_bottom, const Vec2& right_top) noexcept;

    // Common methods
    void intersect(const ObjectBorder& other, std::vector<Intersection>& intersections) const;

    // Interface

    // Getters
    virtual Edge get_edge(size_t index) const noexcept = 0;

    // Statistics
    virtual size_t size() const noexcept = 0;

    // Common methods
    virtual Edge::Intersection intersect_edge(const Edge& edge) const noexcept = 0;

    virtual ~ObjectBorder() {}
};

// Simle box border
class BoxBorder : public ObjectBorder {
    Vec2 points[4];

public:
    using Base = ObjectBorder;

    // Constructors
    BoxBorder() noexcept;

    BoxBorder(const Vec2& left_bottom, const Vec2& right_top) noexcept;

    // Getters
    Edge get_edge(size_t index) const noexcept final;

    // Statistics
    size_t size() const noexcept final;

    // Common methods
    Edge::Intersection intersect_edge(const Edge& edge) const noexcept final;
};
