#ifndef _ENTITY_H
#define _ENTITY_H

#include "app\app.h"
#include "Vector2.h"
#include "Collider.h"
#include "TerrainGenerator.h"

enum AnimType
{
    IDLE_LEFT,
    IDLE_RIGHT,
    MOVE_LEFT,
    MOVE_RIGHT,
    COLLECT_LEFT,
    COLLECT_RIGHT,
    DIE_LEFT,
    DIE_RIGHT
};

class Entity
{
public:
    const int WINDOW_WIDTH = APP_INIT_WINDOW_WIDTH;
    const int WINDOW_HEIGHT = APP_INIT_WINDOW_HEIGHT;
    const float HALF_WINDOW_WIDTH = (WINDOW_WIDTH * 0.5f);
    const float HALF_WINDOW_HEIGHT = (WINDOW_HEIGHT * 0.5f);

public:
    Entity(Vector2& position);
    Entity(float x = 0.0f, float y = 0.0f);
    ~Entity();

    Vector2 GetPosition();
    Vector2 GetScale();
    float GetRotation();
    
    void SetPosition(float x, float y);
    void SetPosition(Vector2& position);
    void SetRotation(float rotation);
    void Translate(Vector2 vector);

    bool GetIsAlive();
    void SetIsAlive(bool yesNo);

    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;

protected:
    TerrainGenerator* p_Terrain;
    Utilities* p_Utilities;
    Collider* p_Collider;
    Vector2 m_Position;
    Vector2 m_Scale;
    float m_Rotation;
    bool m_IsAlive;
    float m_AnimationSpeed;
};
#endif // !_ENTITY_H