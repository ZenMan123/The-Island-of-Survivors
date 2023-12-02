#include "vec2.hpp"
#include <SFML/System/Vector2.hpp>


// Constructors
Vec2::Vec2() noexcept {
}

Vec2::Vec2(double value) noexcept
    : x(value)
    , y(value)
{}

Vec2::Vec2(double x, double y) noexcept
    : x(x)
    , y(y)
{}

Vec2::Vec2(const sf::Vector2f& init) noexcept
    : x(init.x)
    , y(init.y)
{}

// Operators
Vec2::operator sf::Vector2f() const {
    return sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
}

double& Vec2::operator[](size_t index) {
    ENSURE(index <= 1, OutOfRange, "index out of range");

    return index == 0 ? x : y;
}

const double& Vec2::operator[](size_t index) const {
    ENSURE(index <= 1, OutOfRange, "index out of range");

    return index == 0 ? x : y;
}

bool Vec2::operator==(const Vec2& other) const noexcept {
    return equality(x, other.x) && equality(y, other.y);
}

bool Vec2::operator!=(const Vec2& other) const noexcept {
    return !equality(x, other.x) || !equality(y, other.y);
}

Vec2& Vec2::operator+=(const Vec2& other)& noexcept {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& other)& noexcept {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2& Vec2::operator*=(double other)& noexcept {
    x *= other;
    y *= other;
    return *this;
}

Vec2& Vec2::operator/=(double other)& noexcept {
    CHECK(!equality(other, 0.0), "division by zero");

    x /= other;
    y /= other;
    return *this;
}

Vec2& Vec2::operator^=(double other)& noexcept {
    CHECK(x >= 0.0 && y >= 0.0, "raising a negative number to a power");

    x = std::pow(x, other);
    y = std::pow(y, other);
    return *this;
}

Vec2 Vec2::operator-() const noexcept {
    return Vec2(-x, -y);
}

Vec2 Vec2::operator+(const Vec2& other) const noexcept {
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const noexcept {
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(double other) const noexcept {
    return Vec2(x * other, y * other);
}

double Vec2::operator*(const Vec2& other) const noexcept {
    return x * other.x + y * other.y;
}

double Vec2::operator^(const Vec2& other) const noexcept {
    return x * other.y - y * other.x;
}

Vec2 Vec2::operator^(double other) const noexcept {
    CHECK(x >= 0.0 && y >= 0.0, "raising a negative number to a power");

    return Vec2(std::pow(x, other), std::pow(y, other));
}

Vec2 Vec2::operator/(double other) const noexcept {
    CHECK(!equality(other, 0.0), "division by zero");

    return Vec2(x / other, y / other);
}

// Other operations
Vec2 Vec2::multiply(const Vec2& other) const noexcept {
    return Vec2(x * other.x, y * other.y);
}

// Math functions
double Vec2::length() const {
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::normalize() const noexcept {
    double vect_length = length();

    CHECK(!equality(vect_length, 0.0), "null vector normalization");

    return *this / vect_length;
}

Vec2 Vec2::rotate90() const noexcept {
    return Vec2(-y, x);
}

// External operators
std::ostream& operator<<(std::ostream& fout, const Vec2& vector) {
    fout << '(' << vector.x << ", " << vector.y << ')';
    return fout;
}

Vec2 operator*(double value, const Vec2& vector) noexcept {
    return Vec2(vector.x * value, vector.y * value);
}

// External functions
sf::FloatRect to_rect(const Vec2& position, const Vec2& size) {
    return sf::FloatRect(
        sf::Vector2f(position),
        sf::Vector2f(size)
    );
}
