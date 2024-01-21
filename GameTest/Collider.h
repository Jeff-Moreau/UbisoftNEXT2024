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
    void SetWidth(float width);
    void SetHeight(float height);
    void SetCenter(Vector2 center);
    Vector2 GetCenter();

    void Init();
    void Update(float deltaTime);
    void Render();

private:
    Utilities* p_Utilities;
    Vector2 m_CenterPoint;
    Vector2 m_Corners[4];

    float m_Width;
    float m_Height;
};
#endif // !_COLLIDER_H