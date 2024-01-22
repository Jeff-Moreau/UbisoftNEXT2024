/****************************************************************************************
 * Script: AIPlayer.cpp
 * Date: January 21, 2024
 * Description: This is the AIPlayer Object.
 * TODO: Collider Work. more work on the AI system
 * Known Bugs:
 ****************************************************************************************/

#include "stdafx.h"
#include "AIPlayer.h"

AIPlayer::AIPlayer()
{
    p_Collider = new Collider();

    m_Position = Vector2(VectorZero);
    m_TotalApples = 5;
    m_Object = 2;
    m_IsAlive = true;

    SetupTextures();
    SetupCollider();
    SetupAnimations();
}

void AIPlayer::SetupCollider()
{
    p_Collider->SetCenter(m_Position);
    p_Collider->SetWidth(p_AIPlayerTexture->GetWidth() * 4);
    p_Collider->SetHeight(p_AIPlayerTexture->GetHeight() * 4);
    p_Collider->SetDebug(false);
}

void AIPlayer::SetupTextures()
{
    p_AIPlayerTexture = App::CreateSprite(".\\TestData\\Squirrels.bmp", 8, 8);
    p_AIPlayerTexture->SetFrame(33);
    p_AIPlayerTexture->SetPosition(0, 0);
    p_AIPlayerTexture->SetScale(4.0f);
}

void AIPlayer::SetupAnimations()
{
    m_AnimationSpeed = 1.0f / 15.0f;
    p_AIPlayerTexture->CreateAnimation(IDLE_LEFT, m_AnimationSpeed, { 33,34,35,36,37,38 });
    p_AIPlayerTexture->CreateAnimation(DIE_LEFT, m_AnimationSpeed, { 57,58,59,60,61,62,63,64 });
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

int AIPlayer::GetTotalApples()
{
    return m_TotalApples;
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

void AIPlayer::SetTotalApples(int amount)
{
    m_TotalApples += amount;
}

void AIPlayer::SetDebug(bool yesNo)
{
    p_Collider->SetDebug(yesNo);
}

void AIPlayer::ResetPlayer()
{
    m_TotalApples = 5;
    m_IsAlive = true;
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