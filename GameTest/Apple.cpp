#include "stdafx.h"
#include "Apple.h"

Apple::Apple()
{
    m_Falling = false;
    m_IsOnGround = false;
    p_Collider = new Collider();
    m_IsAlive = true;
    m_TerrainHeight = 0;
    //m_Position = Vector2(0, 800);
    p_AppleTexture = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_AppleTexture->SetFrame(1);
    //p_AppleTexture->SetPosition(0, 0);
    p_AppleTexture->SetScale(2.0f);

    p_Collider->SetCenter(m_Position);
    p_Collider->SetWidth(p_AppleTexture->GetWidth() * 2);
    p_Collider->SetHeight(p_AppleTexture->GetHeight() * 2);
}

Apple::~Apple()
{
    delete p_AppleTexture;
    p_AppleTexture = nullptr;
}

float Apple::GetTextureHeight()
{
    return p_AppleTexture->GetHeight();
}

float Apple::GetTextureWidth()
{
    return p_AppleTexture->GetWidth();
}

void Apple::SetTextureScale(float size)
{
    p_AppleTexture->SetScale(size);
}

void Apple::SetTextureFrame(float frame)
{
    p_AppleTexture->SetFrame(frame);
}

bool Apple::IsOnGround()
{
    return m_IsOnGround;
}

void Apple::SetIsOnGround(bool yesNo)
{
    m_IsOnGround = yesNo;
}

void Apple::SetIsAlive(bool yesNo)
{
    m_IsAlive = yesNo;
}

void Apple::ResetApple()
{
    m_IsOnGround = false;
    m_Falling = false;
    m_IsAlive = true;
}

void Apple::TerrainHeight(float height)
{
    m_TerrainHeight = height;
}

void Apple::IsHit(bool yesNo)
{
    m_Falling = yesNo;;
}

void Apple::Init()
{
}

void Apple::Update(float deltaTime)
{
    p_AppleTexture->Update(deltaTime);
    p_AppleTexture->SetPosition(m_Position.x, m_Position.y);
    p_Collider->SetCenter(m_Position);
    p_Collider->Update(deltaTime);

    if (m_Falling)
    {
        m_Position.y = m_Position.y - 10;
    }
    
    if ((m_Position.y - p_AppleTexture->GetHeight()) <= m_TerrainHeight)
    {
        m_Falling = false;
        m_IsOnGround = true;
    }
}

void Apple::Render()
{
    if (m_IsAlive)
    {
        //m_IsOnGround = false;
        p_AppleTexture->Draw();
        p_Collider->Render();
    }
}
