#ifndef _VECTORS_H
#define _VECTORS_H

struct Vector2
{
    float x;
    float y;

    Vector2(float x = 0.0f, float y = 0.0f);
};

const Vector2 VectorZero = { 0.0f, 0.0f };
const Vector2 VectorOne = { 1.0f, 1.0f };
const Vector2 VectorUp = { 0.0f, 1.0f };
const Vector2 VectorDown = { 0.0f, -1.0f };
const Vector2 VectorRight = { 1.0f, 0.0f };
const Vector2 VectorLeft = { -1.0f, 0.0f };

#endif // !_VECTORS_H