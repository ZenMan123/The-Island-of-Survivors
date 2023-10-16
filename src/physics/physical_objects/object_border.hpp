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
        uint8_t number_intersections = 0;

        bool penetrate[2];
        Vec2 intersections[2];
    };
};


// Physical object border interface
class ObjectBorder {
    Vec2 left_bottom_;
    Vec2 right_top_;

    bool has_border_ = false;

public:
    using Ptr = std::shared_ptr<ObjectBorder>;

    // Constructors
    ObjectBorder() noexcept;

    void init(const Vec2& left_bottom, const Vec2& right_top) noexcept;

    // Common methods
    void intersect(ObjectBorder::Ptr other, std::vector<Intersection>& intersections) const;

    // Interface

    // Getters
    [[nodiscard]] virtual Edge get_edge(size_t index) const noexcept = 0;

    // Statistics
    [[nodiscard]] virtual size_t size() const noexcept = 0;

    // Common methods
    [[nodiscard]] virtual Edge::Intersection intersect_edge(const Edge& edge) const noexcept = 0;

    // Destructors
    virtual ~ObjectBorder();

private:
    // Private methods
    [[nodiscard]] bool is_intersect(ObjectBorder::Ptr other) const noexcept;
};


// Simle box border
class BoxBorder : public ObjectBorder {
    Vec2 points[4];

public:
    using Base = ObjectBorder;
    using Ptr = std::shared_ptr<BoxBorder>;

    // Constructors
    BoxBorder() noexcept;

    void init(const Vec2& left_bottom, const Vec2& right_top) noexcept;

    // Getters
    [[nodiscard]] Edge get_edge(size_t index) const noexcept final;

    // Statistics
    [[nodiscard]] size_t size() const noexcept final;

    // Common methods
    [[nodiscard]] Edge::Intersection intersect_edge(const Edge& edge) const noexcept final;

    // Static functions
    template <typename ...Args>
    [[nodiscard]] static BoxBorder::Ptr make(Args&&... args) {
        BoxBorder::Ptr object = std::make_shared<BoxBorder>();
        object->init(std::forward<Args>(args)...);
        return object;
    }
};
