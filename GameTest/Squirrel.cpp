#include "stdafx.h"
#include "Squirrel.h"

Squirrel::Squirrel()
{
    p_Collider = new Collider();
    m_IsAlive = true;
    m_Position = Vector2(VectorZero);
    p_SquirrelTexture = App::CreateSprite(".\\TestData\\Squirrels.bmp", 8, 4);
    p_SquirrelTexture->SetFrame(0);
    p_SquirrelTexture->SetPosition(0, 0);
    p_SquirrelTexture->SetScale(2.0f);

    p_Collider->SetCenter(m_Position);
    p_Collider->SetWidth(p_SquirrelTexture->GetWidth() * 2);
    p_Collider->SetHeight(p_SquirrelTexture->GetHeight() * 2);

    SetupAnimations();
}

void Squirrel::SetupAnimations()
{
    m_AnimationSpeed = 1.0f / 15.0f;
    p_SquirrelTexture->CreateAnimation(IDLE_RIGHT, m_AnimationSpeed, { 0,1,2,3,4,5 });
    p_SquirrelTexture->CreateAnimation(MOVE_RIGHT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    //p_SquirrelTexture->CreateAnimation(COLLECT_RIGHT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    //p_SquirrelTexture->CreateAnimation(DIE_RIGHT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    //p_SquirrelTexture->CreateAnimation(IDLE_LEFT, m_AnimationSpeed, { 0,1,2,3,4,5 });
    //p_SquirrelTexture->CreateAnimation(MOVE_LEFT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    //p_SquirrelTexture->CreateAnimation(COLLECT_LEFT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    //p_SquirrelTexture->CreateAnimation(DIE_LEFT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
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

void Squirrel::SetAnimationType(AnimType animation)
{
    p_SquirrelTexture->SetAnimation(animation);
}

void Squirrel::SetTextureScale(float size)
{
    p_SquirrelTexture->SetScale(size);
}

void Squirrel::Init()
{
}

void Squirrel::Update(float deltaTime)
{
    p_SquirrelTexture->Update(deltaTime);
    p_SquirrelTexture->SetPosition(m_Position.x, m_Position.y);
    p_Collider->SetCenter(m_Position);
    p_Collider->Update(deltaTime);
}

void Squirrel::Render()
{
    if (m_IsAlive)
    {
        p_SquirrelTexture->Draw();
        p_Collider->Render();
    }
}