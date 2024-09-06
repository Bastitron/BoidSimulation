#pragma once

#include <cmath>

class Vector2 {
public:
    float x;
    float y;

    Vector2() = default;

    Vector2(float xc, float yc) {
        x = xc;
        y = yc;
    }

    float Distance(Vector2 &vector) const {
        float delta_x = x - vector.x;
        float delta_y = y - vector.y;

        return std::sqrt((delta_x * delta_x) + (delta_y * delta_y));
    }

    float Magnitude() {
        return std::sqrt((x * x) + (y * y));
    }

    Vector2 &operator+(Vector2& vector) {
        x += vector.x;
        y += vector.y;

        return *this;
    }

    Vector2 &operator-(Vector2 &vector) {
        x -= vector.x;
        y -= vector.y;

        return *this;
    }

    Vector2 &operator/(Vector2& vector) {
        x /= vector.x;
        y /= vector.y;

        return *this;
    }

    Vector2 &operator*(Vector2& vector) {
        x *= vector.x;
        y *= vector.y;

        return *this;
    }
};
