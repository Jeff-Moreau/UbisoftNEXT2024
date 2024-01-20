#include "stdafx.h"
#include "Entity.h"


Entity::Entity(Vector2& position)
{
    m_Position = Vector2(position);
    m_Scale = Vector2(VectorZero);
    m_Rotation = 0.0f;
}

Entity::Entity(float x, float y)
{
    m_Position = Vector2(x, y);
    m_Scale = Vector2(VectorZero);
    m_Rotation = 0.0f;
}

Entity::~Entity()
{

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

void Entity::SetScale(float x, float y)
{
    m_Scale = Vector2(x, y);
}

void Entity::SetScale(Vector2& scale)
{
    m_Scale = scale;
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