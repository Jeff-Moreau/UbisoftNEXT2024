#include "stdafx.h"
#include "Squirrel.h"

Squirrel::Squirrel()
{
    p_Collider = new Collider();
    m_GetApple = false;
    m_PickUpApple = false;
    m_IsCollecting = false;
    m_MoveSpeed = 5;
    m_Count = 0;
    m_IsAlive = true;
    m_Position = Vector2(VectorZero);

    p_SquirrelTexture = App::CreateSprite(".\\TestData\\Squirrels.bmp", 8, 8);
    p_SquirrelTexture->SetFrame(0);
    p_SquirrelTexture->SetPosition(0, 0);
    p_SquirrelTexture->SetScale(2.0f);

    p_Collider->SetCenter(m_Position);
    p_Collider->SetWidth(p_SquirrelTexture->GetWidth() * 2);
    p_Collider->SetHeight(p_SquirrelTexture->GetHeight() * 2);
    p_Collider->SetDebug(false);

    SetupAnimations();
}

void Squirrel::SetupAnimations()
{
    m_AnimationSpeed = 1.0f / 15.0f;
    p_SquirrelTexture->CreateAnimation(IDLE_RIGHT, m_AnimationSpeed, { 0,1,2,3,4,5 });
    p_SquirrelTexture->CreateAnimation(MOVE_RIGHT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    p_SquirrelTexture->CreateAnimation(COLLECT_RIGHT, m_AnimationSpeed, { 17,18,19,20,21,22 });
    p_SquirrelTexture->CreateAnimation(DIE_RIGHT, m_AnimationSpeed, { 25,26,27,28,29,30,31,32 });
}

Squirrel::~Squirrel()
{
    delete p_SquirrelTexture;
    p_SquirrelTexture = nullptr;
}

float Squirrel::GetTextureHeight()
{
    return p_SquirrelTexture->GetHeight();
}

float Squirrel::GetTextureWidth()
{
    return p_SquirrelTexture->GetWidth();
}

void Squirrel::SetAnimationType(AnimType animation)
{
    p_SquirrelTexture->SetAnimation(animation);
}

void Squirrel::SetTextureScale(float size)
{
    p_SquirrelTexture->SetScale(size);
}

void Squirrel::GetApples()
{
    m_GetApple = true;
}

void Squirrel::PickUpApple()
{
    m_PickUpApple = true;
}

bool Squirrel::Collecting()
{
    return m_IsCollecting;
}

void Squirrel::ResetSquirrel()
{
    m_GetApple = false;
    m_PickUpApple = false;
    m_IsCollecting = false;
    m_IsAlive = true;
}

void Squirrel::IsHit()
{
    
}

void Squirrel::SetDebug(bool yesNo)
{
    p_Collider->SetDebug(yesNo);
}

void Squirrel::Init()
{
}

void Squirrel::Update(float deltaTime)
{
    m_Count += (deltaTime / 1000);

    p_SquirrelTexture->Update(deltaTime);
    p_SquirrelTexture->SetPosition(m_Position.x, m_Position.y);
    p_Collider->SetCenter(m_Position);
    p_Collider->Update(deltaTime);

    if (m_GetApple)
    {
        p_SquirrelTexture->SetAnimation(MOVE_RIGHT);
        m_Position.x = m_Position.x + m_MoveSpeed;
    }

    if (m_PickUpApple)
    {
        m_GetApple = false;
        m_IsCollecting = true;
        p_SquirrelTexture->SetAnimation(COLLECT_RIGHT);
    }
}

void Squirrel::Render()
{
    if (m_IsAlive)
    {
        p_SquirrelTexture->Draw();
        p_Collider->Render();
    }
}
