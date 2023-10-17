#include "object_border.hpp"


//// Edge

Edge& Edge::apply_dircetion(const Vec2& dircetion) {
    start -= dircetion;
    end -= dircetion;
    return *this;
}


//// ObjectBorder

// Constructors
ObjectBorder::ObjectBorder() noexcept {
}

void ObjectBorder::init(const Vec2& left_bottom, const Vec2& right_top) noexcept {
    left_bottom_ = left_bottom;
    right_top_ = right_top;
    has_border_ = true;
}

// Getters
const BorderState& ObjectBorder::get_state() const noexcept {
    return state_;
}

// Common methods
void ObjectBorder::intersect(ObjectBorder::Ptr other, const Vec2& dircetion, std::vector<Intersection>& intersections) {
    if (!is_intersect(other, dircetion)) {
        return;
    }

    int number_intersections = 0;
    Vec2 first_point;
    Vec2 last_point;
    for (size_t i = 0; i < size() && number_intersections < 2; ++i) {
        Edge::Intersection intersection = other->intersect_edge(get_edge(i).apply_dircetion(dircetion));
        number_intersections += intersection.number_intersections;

        for (size_t id = 0; id < intersection.number_intersections; ++id) {
            if (intersection.penetrate[id]) {
                first_point = intersection.intersections[id];
            } else {
                last_point = intersection.intersections[id];
            }
        }
    }

    if (number_intersections > 0) {
        state_.intersected = true;
        intersections.push_back({.penetration = (last_point - first_point).length(), .direction = (last_point - first_point).rotate90()});
    }
}

void ObjectBorder::drop_state() noexcept {
    state_.intersected = false;
}

// Private methods
bool ObjectBorder::is_intersect(ObjectBorder::Ptr other, const Vec2& dircetion) const noexcept {
    Vec2 left_bottom = left_bottom_ - dircetion;
    Vec2 right_top = right_top_ - dircetion;

    ObjectBorder::Ptr ср = other;

    return !has_border_ || !other->has_border_
        || std::max(left_bottom.x, other->left_bottom_.x) + EPS <= std::min(right_top.x, other->right_top_.x) - EPS
        || std::max(left_bottom.y, other->left_bottom_.y) + EPS <= std::min(right_top.y, other->right_top_.y) - EPS;
}

// Destructors
ObjectBorder::~ObjectBorder() {
}

//// BoxBorder

// Constructors
BoxBorder::BoxBorder() noexcept : Base()
{}

void BoxBorder::init(const Vec2& left_bottom, const Vec2& right_top) noexcept {
    Base::init(left_bottom, right_top);
    
    points[0] = left_bottom;
    points[1] = Vec2(left_bottom.x, right_top.y);
    points[2] = right_top;
    points[3] = Vec2(right_top.x, left_bottom.y);
}

// Getters
Edge BoxBorder::get_edge(size_t index) const noexcept {
    return {.start = points[index % 4], .end = points[(index + 1) % 4]};
}

// Statistics
size_t BoxBorder::size() const noexcept {
    return 4;    
}

// Common methods
Edge::Intersection BoxBorder::intersect_edge(const Edge& edge) noexcept {
    Edge::Intersection result;
    if (equality(edge.start.x, edge.end.x)) {
        double edge_x = edge.start.x;

        Edge top = get_edge(1);
        Edge bottom = get_edge(3);

        if (edge_x < top.start.x + EPS || top.end.x - EPS < edge_x) {
            return result;
        }

        double top_y = std::max(edge.start.y, edge.end.y);
        double bottom_y = std::min(edge.start.y, edge.end.y);

        if (bottom_y > top.start.y - EPS || top_y < bottom.start.y + EPS) {
            return result;
        }
        
        state_.intersected = true;
        if (bottom_y > bottom.start.y - EPS) {
            result.number_intersections = 1;
            result.intersections[0] = Vec2(edge_x, top.start.y);
            result.penetrate[0] = edge.start.y > edge.end.y;
        } else if (top_y < top.start.y + EPS) {
            result.number_intersections = 1;
            result.intersections[0] = Vec2(edge_x, bottom.start.y);
            result.penetrate[0] = edge.start.y < edge.end.y;
        } else {
            result.number_intersections = 2;
            result.intersections[0] = Vec2(edge_x, top.start.y);
            result.intersections[1] = Vec2(edge_x, bottom.start.y);
            result.penetrate[0] = edge.start.y > edge.end.y;
            result.penetrate[1] = edge.start.y < edge.end.y;
        }
    } else {
        double edge_y = edge.start.y;

        Edge left = get_edge(0);
        Edge right = get_edge(2);

        if (edge_y < left.start.y + EPS || left.end.y - EPS < edge_y) {
            return result;
        }

        double right_x = std::max(edge.start.x, edge.end.x);
        double left_x = std::min(edge.start.x, edge.end.x);

        if (left_x > right.start.x - EPS || right_x < left.start.x + EPS) {
            return result;
        }

        state_.intersected = true;
        if (left_x > left.start.x - EPS) {
            result.number_intersections = 1;
            result.intersections[0] = Vec2(right.start.x, edge_y);
            result.penetrate[0] = edge.start.x > edge.end.x;
        } else if (right_x < right.start.x + EPS) {
            result.number_intersections = 1;
            result.intersections[0] = Vec2(left.start.x, edge_y);
            result.penetrate[0] = edge.start.x < edge.end.x;
        } else {
            result.number_intersections = 2;
            result.intersections[0] = Vec2(right.start.x, edge_y);
            result.intersections[1] = Vec2(left.start.x, edge_y);
            result.penetrate[0] = edge.start.x > edge.end.x;
            result.penetrate[1] = edge.start.x < edge.end.x;
        }
    }
    return result;
}
