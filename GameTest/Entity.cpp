#include "stdafx.h"
#include "Entity.h"


Entity::Entity(Vector2& position)
{
    m_IsAlive = true;
    m_Position = Vector2(position);
    m_Scale = Vector2(VectorZero);
    m_Rotation = 0.0f;
    p_Terrain = new TerrainGenerator();
    p_Utilities = new Utilities();
}

Entity::Entity(float x, float y)
{
    m_IsAlive = true;
    m_Position = Vector2(x, y);
    m_Scale = Vector2(VectorZero);
    m_Rotation = 0.0f;
    p_Terrain = new TerrainGenerator();
    p_Utilities = new Utilities();
}

Entity::~Entity()
{
    delete p_Terrain;
    p_Terrain = nullptr;

    delete p_Utilities;
    p_Utilities = nullptr;
}

Vector2 Entity::GetPosition()
{
    return m_Position;
}

Vector2 Entity::GetScale()
{
    return m_Scale;
}

float Entity::GetRotation()
{
    return m_Rotation;
}

void Entity::SetPosition(float x, float y)
{
    m_Position = Vector2(x, y);
}

void Entity::SetPosition(Vector2& position)
{
    m_Position = position;
}


void Entity::SetRotation(float rotation)
{
    m_Rotation = rotation;
    
    while (m_Rotation > 360.0f)
    {
        m_Rotation -= 360.0f;
    }

    while (m_Rotation < 0.0f)
    {
        m_Rotation += 360.0f;
    }
}

void Entity::Translate(Vector2 vector)
{
    m_Position += vector;
}

bool Entity::GetIsAlive()
{
    return m_IsAlive;
}

void Entity::SetIsAlive(bool yesNo)
{
    m_IsAlive = yesNo;
}
