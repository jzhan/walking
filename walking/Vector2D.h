/* by Wildan R. */

#pragma once

#include <raylib.h>
#include <math.h>

struct Vector2D : public Vector2
{
    Vector2D(float x, float y);
    Vector2D(float x);
    Vector2D();
    float Length() const;
    float DotProduct(Vector2D vec) const;
    Vector2D Add(Vector2D vec) const;
    Vector2D Subtract(Vector2D vec) const;
    Vector2D Scale(float scale) const;
    Vector2D Normalize() const;
    Vector2D Rotate(float angle) const;
};

inline Vector2D::Vector2D(float x, float y) : Vector2{ x, y } {}

inline Vector2D::Vector2D(float x) : Vector2{ x, 0.0f } {}

inline Vector2D::Vector2D() : Vector2{ 0.0f, 0.0f } {}

inline float Vector2D::Length() const
{
    return float{ sqrtf((x * x) + (y * y)) };
}

inline float Vector2D::DotProduct(Vector2D vec) const
{
    return float{ x * vec.x + y * vec.y };
}

inline Vector2D Vector2D::Add(Vector2D vec) const
{
    return Vector2D{ x + vec.x, y + vec.y };
}

inline Vector2D Vector2D::Subtract(Vector2D vec) const
{
    return Vector2D{ x - vec.x, y - vec.y };
}

inline Vector2D Vector2D::Scale(float scale) const
{
    return Vector2D{ x * scale, y * scale };
}

inline Vector2D Vector2D::Normalize() const
{
    Vector2D result{};

    float length{ sqrtf((x * x) + (y * y)) };

    if (length > 0)
    {
        float ilength = 1.0f / length;
        result.x = x * ilength;
        result.y = y * ilength;
    }

    return result;
}

inline Vector2D Vector2D::Rotate(float angle) const
{
    Vector2D result{};

    float cosres{ cosf(angle) };
    float sinres{ sinf(angle) };

    result.x = x * cosres - y * sinres;
    result.y = x * sinres + y * cosres;

    return result;
}