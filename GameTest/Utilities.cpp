#include "stdafx.h"
#include "Utilities.h"

Utilities::Utilities()
{
    srand(time(NULL));
}

Utilities::~Utilities()
{
}

float Utilities::Distance(Vector2 from, Vector2 to)
{
    float x = (from.x - to.x) * (from.x - to.x);
    float y = (from.y - to.y) * (from.y - to.y);
    return sqrtf(x + y);
}

float Utilities::RandomNumber(int low, int high)
{
    return rand() % (high - low + 1) + low;
}