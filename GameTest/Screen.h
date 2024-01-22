/****************************************************************************************
 * Script: Screen.h
 * Date: January 21, 2024
 * Description: Template for all Screens to use
 * TODO: 
 * Known Bugs:
 ****************************************************************************************/

#ifndef _SCREEN_H
#define _SCREEN_H

#include "app\app.h"

class Screen
{
public:
    const int TEXT_SPACING = 25;
    const int CHAR_WIDTH = 4;
    const int WINDOW_WIDTH = APP_INIT_WINDOW_WIDTH;
    const int WINDOW_HEIGHT = APP_INIT_WINDOW_HEIGHT;
    const float HALF_WINDOW_WIDTH = (WINDOW_WIDTH * 0.5f);
    const float HALF_WINDOW_HEIGHT = (WINDOW_HEIGHT * 0.5f);

public:
    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;
};
#endif // !_SCREEN_H