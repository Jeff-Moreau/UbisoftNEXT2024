#include "stdafx.h"
#include "AIPlayer.h"

AIPlayer::AIPlayer()
{
    m_TotalApples = 5;
    m_Object = 1;
    p_Collider = new Collider();
    m_IsAlive = true;
    m_Position = Vector2(VectorZero);
    p_AIPlayerTexture = App::CreateSprite(".\\TestData\\Squirrels.bmp", 8, 4);
    p_AIPlayerTexture->SetFrame(0);
    p_AIPlayerTexture->SetPosition(0, 0);
    p_AIPlayerTexture->SetScale(4.0f);

    p_Collider->SetCenter(m_Position);
    p_Collider->SetWidth(p_AIPlayerTexture->GetWidth() * 4);
    p_Collider->SetHeight(p_AIPlayerTexture->GetHeight() * 4);

    SetupAnimations();
}

void AIPlayer::SetupAnimations()
{
    m_AnimationSpeed = 1.0f / 15.0f;
    //p_AIPlayerTexture->CreateAnimation(IDLE_LEFT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
    //p_AIPlayerTexture->CreateAnimation(DIE_LEFT, m_AnimationSpeed, { 9,10,11,12,13,14,15,16 });
}

AIPlayer::~AIPlayer()
{
    delete p_AIPlayerTexture;
    p_AIPlayerTexture = nullptr;
}

float AIPlayer::GetTextureHeight()
{
    return p_AIPlayerTexture->GetHeight();
}

int AIPlayer::GetObjectID()
{
    return m_Object;;
}

void AIPlayer::SetTextureScale(float size)
{
    p_AIPlayerTexture->SetScale(size);
}

void AIPlayer::SetAnimationType(AnimType animation)
{
    p_AIPlayerTexture->SetAnimation(animation);
}

void AIPlayer::SetTextureFrame(float frame)
{
    p_AIPlayerTexture->SetFrame(frame);
}

int AIPlayer::GetTotalApples()
{
    return m_TotalApples;
}

void AIPlayer::ResetPlayer()
{
    m_TotalApples = 5;
    m_IsAlive = true;
}

void AIPlayer::SetTotalApples(int amount)
{
    m_TotalApples += amount;
}


void AIPlayer::Init()
{
}

void AIPlayer::Update(float deltaTime)
{
    p_AIPlayerTexture->Update(deltaTime);
    p_AIPlayerTexture->SetPosition(m_Position.x, m_Position.y);
    p_Collider->SetCenter(m_Position);
    p_Collider->Update(deltaTime);
}

void AIPlayer::Render()
{
    p_AIPlayerTexture->Draw();
    p_Collider->Render();
}