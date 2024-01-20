#include "stdafx.h"
#include "Utilities.h"

Utilities::Utilities()
{
    srand(time(NULL));
}

Utilities::~Utilities()
{
}

float Utilities::RandomNumber(int low, int high)
{
    return rand() % (high - low + 1) + low;
}
