/****************************************************************************************
 * Script: Collider.h
 * Date: January 21, 2024
 * Description: Used for testing collisions between 2 objects
 * TODO: work in progress, needs more work to get it to function properly.
 * Known Bugs:
 ****************************************************************************************/

#ifndef _COLLIDER_H
#define _COLLIDER_H_

#include "App/app.h"
#include "Vector2.h"
#include "Utilities.h"

class Collider
{
public:
    Collider();
    ~Collider();

public:
    Vector2 GetCenter() const;

    void SetWidth(float width);
    void SetHeight(float height);
    void SetCenter(Vector2 center);
    void SetDebug(bool yesNo);

    void Init();
    void Update(float deltaTime);
    void Render();

private:
    Utilities* p_Utilities;

    Vector2 m_CenterPoint;
    Vector2 m_Corners[4];
    bool m_IsDebugSet;
    float m_Width;
    float m_Height;
};
#endif // !_COLLIDER_H