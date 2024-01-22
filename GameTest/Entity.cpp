/****************************************************************************************
 * Script: Entity.cpp
 * Date: January 21, 2024
 * Description: This is a base class for every item in the program
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#include "stdafx.h"
#include "Entity.h"


Entity::Entity(Vector2& position)
{
    p_Terrain = new TerrainGenerator();
    p_Utilities = new Utilities();
    p_Collider = new Collider();

    m_Position = Vector2(position);
    m_Scale = Vector2(VectorZero);
    m_AnimationSpeed = 1.0f;
    m_Rotation = 0.0f;
    m_IsAlive = true;
}

Entity::Entity(float x, float y)
{
    p_Terrain = new TerrainGenerator();
    p_Utilities = new Utilities();
    p_Collider = new Collider();

    m_Scale = Vector2(VectorZero);
    m_Position = Vector2(x, y);
    m_AnimationSpeed = 1.0f;
    m_Rotation = 0.0f;
    m_IsAlive = true;
}

Entity::~Entity()
{
    delete p_Terrain;
    p_Terrain = nullptr;

    delete p_Utilities;
    p_Utilities = nullptr;

    delete p_Collider;
    p_Collider = nullptr;
}

Vector2 Entity::GetPosition() const
{
    return m_Position;
}

Vector2 Entity::GetScale() const
{
    return m_Scale;
}

float Entity::GetRotation() const
{
    return m_Rotation;
}

bool Entity::GetIsAlive() const
{
    return m_IsAlive;
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

void Entity::SetIsAlive(bool yesNo)
{
    m_IsAlive = yesNo;
}

void Entity::Translate(Vector2 vector)
{
    m_Position += vector;
}