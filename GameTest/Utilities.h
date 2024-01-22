/****************************************************************************************
 * Script: Utilities.h
 * Date: January 21, 2024
 * Description: This provides some functionality for Numbers
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#ifndef _UTILITIES_H
#define _UTILITIES_H

#include <time.h>
#include <stdlib.h>
#include "Vector2.h"

class Utilities
{
public:
    Utilities();
    ~Utilities();

    float Distance(Vector2 from, Vector2 to);
    float RandomNumber(int low, int high);
};
#endif // !_UTILITIES_H