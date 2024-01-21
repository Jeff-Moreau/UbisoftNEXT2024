#include "stdafx.h"
#include "AISquirrel.h"

AISquirrel::AISquirrel()
{
    p_Collider = new Collider();
    m_GetApple = false;
    m_PickUpApple = false;
    m_IsCollecting = false;
    m_MoveSpeed = 1;
    m_Count = 0;
    m_IsAlive = true;
    m_Position = Vector2(VectorZero);

    p_AISquirrelTexture = App::CreateSprite(".\\TestData\\Squirrels.bmp", 8, 8);
    p_AISquirrelTexture->SetFrame(33);
    p_AISquirrelTexture->SetPosition(0, 0);
    p_AISquirrelTexture->SetScale(2.0f);

    p_Collider->SetCenter(m_Position);
    p_Collider->SetWidth(p_AISquirrelTexture->GetWidth() * 2);
    p_Collider->SetHeight(p_AISquirrelTexture->GetHeight() * 2);
    p_Collider->SetDebug(false);

    SetupAnimations();
}

void AISquirrel::SetupAnimations()
{
    m_AnimationSpeed = 1.0f / 15.0f;
    p_AISquirrelTexture->CreateAnimation(IDLE_LEFT, m_AnimationSpeed, { 33,34,35,36,37,38 });
    p_AISquirrelTexture->CreateAnimation(MOVE_LEFT, m_AnimationSpeed, { 41,42,43,44,45,46,47,48 });
    p_AISquirrelTexture->CreateAnimation(COLLECT_LEFT, m_AnimationSpeed, { 49,50,51,52,53,54 });
    p_AISquirrelTexture->CreateAnimation(DIE_LEFT, m_AnimationSpeed, { 57,58,59,60,61,62,63,64 });
}

AISquirrel::~AISquirrel()
{
    delete p_AISquirrelTexture;
    p_AISquirrelTexture = nullptr;
}

float AISquirrel::GetTextureHeight()
{
    return p_AISquirrelTexture->GetHeight();
}

float AISquirrel::GetTextureWidth()
{
    return p_AISquirrelTexture->GetWidth();
}

void AISquirrel::SetAnimationType(AnimType animation)
{
    p_AISquirrelTexture->SetAnimation(animation);
}

void AISquirrel::SetTextureScale(float size)
{
    p_AISquirrelTexture->SetScale(size);
}

void AISquirrel::GetApples()
{
    m_GetApple = true;
}

void AISquirrel::PickUpApple()
{
    m_PickUpApple = true;
}

bool AISquirrel::Collecting()
{
    return m_IsCollecting;
}

void AISquirrel::ResetSquirrel()
{
    m_GetApple = false;
    m_PickUpApple = false;
    m_IsCollecting = false;
    m_IsAlive = true;
}

void AISquirrel::SetDebug(bool yesNo)
{
    p_Collider->SetDebug(yesNo);
}

void AISquirrel::Init()
{
}

void AISquirrel::Update(float deltaTime)
{
    m_Count += (deltaTime / 1000);

    p_AISquirrelTexture->Update(deltaTime);
    p_AISquirrelTexture->SetPosition(m_Position.x, m_Position.y);
    p_Collider->SetCenter(m_Position);
    p_Collider->Update(deltaTime);

    if (m_GetApple)
    {
        p_AISquirrelTexture->SetAnimation(MOVE_RIGHT);
        m_Position.x = m_Position.x + m_MoveSpeed;
        m_Position.y = p_Terrain->GetTerrainHeightAt(m_Position.x + 32) + (p_AISquirrelTexture->GetHeight() * 0.5f);
    }

    if (m_PickUpApple)
    {
        m_GetApple = false;
        m_IsCollecting = true;
        p_AISquirrelTexture->SetAnimation(COLLECT_RIGHT);
    }
}

void AISquirrel::Render()
{
    if (m_IsAlive)
    {
        p_AISquirrelTexture->Draw();
        p_Collider->Render();
    }
}