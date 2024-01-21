#include "stdafx.h"
#include "Collider.h"

Collider::Collider()
{
    p_Utilities = new Utilities();
    m_CenterPoint = Vector2(VectorZero);
    m_IsDebugSet = false;
    for (int i = 0; i < 4; i++)
    {
        m_Corners[i] = (Vector2(VectorZero));
    }

    m_Width = 0;
    m_Height = 0;
}

Collider::~Collider()
{
}

void Collider::SetWidth(float width)
{
    m_Width = width * 0.5f;
}

void Collider::SetHeight(float height)
{
    m_Height = height * 0.5f;
}

void Collider::SetCenter(Vector2 center)
{
    m_CenterPoint = center;
}

Vector2 Collider::GetCenter()
{
    return m_CenterPoint;
}

void Collider::SetDebug(bool yesNo)
{
    m_IsDebugSet = yesNo;
}

void Collider::Init()
{
}

void Collider::Update(float deltaTime)
{
    m_Corners[0] = Vector2(m_CenterPoint.x - m_Width, m_CenterPoint.y + m_Height);
    m_Corners[1] = Vector2(m_CenterPoint.x + m_Width, m_CenterPoint.y + m_Height);
    m_Corners[2] = Vector2(m_CenterPoint.x + m_Width, m_CenterPoint.y - m_Height);
    m_Corners[3] = Vector2(m_CenterPoint.x - m_Width, m_CenterPoint.y - m_Height);
}

void Collider::Render()
{
    if (m_IsDebugSet)
    {
        App::DrawLine(m_Corners[0].x, m_Corners[0].y, m_Corners[1].x, m_Corners[1].y);
        App::DrawLine(m_Corners[1].x, m_Corners[1].y, m_Corners[2].x, m_Corners[2].y);
        App::DrawLine(m_Corners[2].x, m_Corners[2].y, m_Corners[3].x, m_Corners[3].y);
        App::DrawLine(m_Corners[3].x, m_Corners[3].y, m_Corners[0].x, m_Corners[0].y);
    }
}
