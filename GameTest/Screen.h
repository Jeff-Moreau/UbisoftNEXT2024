#ifndef _SCREEN_H
#define _SCREEN_H

#include "app\app.h"

class Screen
{
public:
    const int TEXT_SPACING = 25;
public:
    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;
};
#endif // !_SCREEN_H