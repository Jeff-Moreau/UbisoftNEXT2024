#ifndef _ENTITY_H
#define _ENTITY_H

#include "Vector2.h"

class Entity
{
public:
    Entity(Vector2& position);
    Entity(float x = 0.0f, float y = 0.0f);
    ~Entity();

    Vector2 GetPosition();
    Vector2 GetScale();
    float GetRotation();
    
    void SetPosition(float x, float y);
    void SetPosition(Vector2& position);
    void SetScale(float x, float y);
    void SetScale(Vector2& scale);
    void SetRotation(float rotation);

private:
    Vector2 m_Position;
    Vector2 m_Scale;
    float m_Rotation;
};
#endif // !_ENTITY_H