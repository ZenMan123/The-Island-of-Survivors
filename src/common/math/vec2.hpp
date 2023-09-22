#pragma once

#include <common/utils/functions.hpp>

#include <SFML/Graphics.hpp>


// Representation of a two-dimensional vector
class Vec2 {
public:
    double x = 0.0;
    double y = 0.0;

    // Constructors
    Vec2() noexcept;

    explicit Vec2(double value) noexcept;

    Vec2(double x, double y) noexcept;

    template <typename T>  // Casts required: double(T)
    Vec2(const std::initializer_list<T>& init) {
        ENSURE(init.size() == 2, InvalidArgument, "invalid initializer list size");

        size_t comp_id = 0;
        for (const T& element : init) {
            (*this)[comp_id++] = static_cast<double>(element);
        }
    }

    explicit Vec2(const sf::Vector2f& init) noexcept;

    // Operators
    explicit operator sf::Vector2f() const;

    double& operator[](size_t index);

    const double& operator[](size_t index) const;

    bool operator==(const Vec2& other) const noexcept;

    bool operator!=(const Vec2& other) const noexcept;

    Vec2& operator+=(const Vec2& other)& noexcept;

    Vec2& operator-=(const Vec2& other)& noexcept;

    Vec2& operator*=(double other)& noexcept;

    Vec2& operator/=(double other)& noexcept;

    Vec2& operator^=(double other)& noexcept;

    Vec2 operator-() const noexcept;

    Vec2 operator+(const Vec2& other) const noexcept;

    Vec2 operator-(const Vec2& other) const noexcept;

    Vec2 operator*(double other) const noexcept;

    double operator*(const Vec2& other) const noexcept;

    double operator^(const Vec2& other) const noexcept;

    Vec2 operator^(double other) const noexcept;

    Vec2 operator/(double other) const noexcept;

    // Math functions
    double length() const;

    Vec2 normalize() const noexcept;
};

// External operators
std::ostream& operator<<(std::ostream& fout, const Vec2& vector);

Vec2 operator*(double value, const Vec2& vector) noexcept;

// External functions
sf::FloatRect to_rect(const Vec2& position, const Vec2& size);
