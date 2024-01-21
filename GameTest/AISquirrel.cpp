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

    p_AISquirrelTexture = App::CreateSprite(".\\TestData\\AISquirrels.bmp", 8, 4);
    p_AISquirrelTexture->SetFrame(0);
    p_AISquirrelTexture->SetPosition(0, 0);
    p_AISquirrelTexture->SetScale(2.0f);

    p_Collider->SetCenter(m_Position);
    p_Collider->SetWidth(p_AISquirrelTexture->GetWidth() * 2);
    p_Collider->SetHeight(p_AISquirrelTexture->GetHeight() * 2);

    SetupAnimations();
}

void AISquirrel::SetupAnimations()
{
    m_AnimationSpeed = 1.0f / 15.0f;
    p_AISquirrelTexture->CreateAnimation(IDLE_RIGHT, m_AnimationSpeed, { 0,1,2,3,4,5 });
    p_AISquirrelTexture->CreateAnimation(MOVE_RIGHT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    p_AISquirrelTexture->CreateAnimation(COLLECT_RIGHT, m_AnimationSpeed, { 17,18,19,20,21,22 });
    p_AISquirrelTexture->CreateAnimation(DIE_RIGHT, m_AnimationSpeed, { 25,26,27,28,29,30,31,32 });
    p_AISquirrelTexture->CreateAnimation(IDLE_LEFT, m_AnimationSpeed, { 0,1,2,3,4,5 });
    p_AISquirrelTexture->CreateAnimation(MOVE_LEFT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    p_AISquirrelTexture->CreateAnimation(COLLECT_LEFT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    p_AISquirrelTexture->CreateAnimation(DIE_LEFT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
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