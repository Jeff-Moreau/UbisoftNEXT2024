#include "stdafx.h"
#include "Apple.h"

Apple::Apple()
{
    m_IsOnGround = false;
    p_Collider = new Collider();
    m_IsAlive = true;
    m_Position = Vector2(VectorZero);
    p_AppleTexture = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_AppleTexture->SetFrame(1);
    p_AppleTexture->SetPosition(0, 0);
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

void Apple::Init()
{
}

void Apple::Update(float deltaTime)
{
    p_AppleTexture->Update(deltaTime);
    p_AppleTexture->SetPosition(m_Position.x, m_Position.y);
    p_Collider->SetCenter(m_Position);
    p_Collider->Update(deltaTime);
}

void Apple::Render()
{
    if (m_IsAlive)
    {
        p_AppleTexture->Draw();
        p_Collider->Render();
    }
}
