#ifndef _VECTORS_H
#define _VECTORS_H

#include <math.h>

struct Vector2
{
    float x;
    float y;

    Vector2(float x = 0.0f, float y = 0.0f);
	
	Vector2& operator+=(const Vector2& rightHandSide)
	{
		x += rightHandSide.x;
		y += rightHandSide.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& rightHandSide)
	{
		x -= rightHandSide.x;
		y -= rightHandSide.y;
		return *this;
	}
};

const Vector2 VectorZero = { 0.0f, 0.0f };
const Vector2 VectorOne = { 1.0f, 1.0f };
const Vector2 VectorUp = { 0.0f, 1.0f };
const Vector2 VectorDown = { 0.0f, -1.0f };
const Vector2 VectorRight = { 1.0f, 0.0f };
const Vector2 VectorLeft = { -1.0f, 0.0f };

inline Vector2 operator+(const Vector2& leftHandSide, const Vector2& rightHandSide)
{
	return Vector2(leftHandSide.x + rightHandSide.x, leftHandSide.y + rightHandSide.y);
}

inline Vector2 operator-(const Vector2& leftHandSide, const Vector2& rightHandSide)
{
	return Vector2(leftHandSide.x - rightHandSide.x, leftHandSide.y - rightHandSide.y);
}

inline Vector2 operator*(const Vector2& leftHandSide, float rightHandSide)
{
	return Vector2(leftHandSide.x * rightHandSide, leftHandSide.y * rightHandSide);
}

inline Vector2 operator*(float leftHandSide, const Vector2& rightHandSide)
{
	return Vector2(leftHandSide * rightHandSide.x, leftHandSide * rightHandSide.y);
}
#endif // !_VECTORS_H