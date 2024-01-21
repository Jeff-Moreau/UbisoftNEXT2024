#include "stdafx.h"
#include "Player.h"

Player::Player()
{
    m_TotalApples = 5;
    m_Object = 1;
    p_Collider = new Collider();
    m_IsAlive = true;
    m_Position = Vector2(VectorZero);
    p_PlayerTexture = App::CreateSprite(".\\TestData\\Squirrels.bmp", 8, 8);
    p_PlayerTexture->SetFrame(0);
    p_PlayerTexture->SetPosition(0, 0);
    p_PlayerTexture->SetScale(4.0f);

    p_Collider->SetCenter(m_Position);
    p_Collider->SetWidth(p_PlayerTexture->GetWidth() * 4);
    p_Collider->SetHeight(p_PlayerTexture->GetHeight()* 4);
    p_Collider->SetDebug(false);

    SetupAnimations();
}

void Player::SetupAnimations()
{
    m_AnimationSpeed = 1.0f / 15.0f;
    p_PlayerTexture->CreateAnimation(IDLE_RIGHT, m_AnimationSpeed, { 0,1,2,3,4,5 });
    p_PlayerTexture->CreateAnimation(DIE_RIGHT, m_AnimationSpeed, { 25,26,27,28,29,30,31,32 });
}

Player::~Player()
{
    delete p_PlayerTexture;
    p_PlayerTexture = nullptr;
}

float Player::GetTextureHeight()
{
    return p_PlayerTexture->GetHeight();
}

int Player::GetObjectID()
{
    return m_Object;;
}

void Player::SetTextureScale(float size)
{
    p_PlayerTexture->SetScale(size);
}

void Player::SetAnimationType(AnimType animation)
{
    p_PlayerTexture->SetAnimation(animation);
}

void Player::SetTextureFrame(float frame)
{
    p_PlayerTexture->SetFrame(frame);
}

int Player::GetTotalApples()
{
    return m_TotalApples;
}

void Player::SetTotalApples(int amount)
{
    m_TotalApples += amount;
}

void Player::ResetPlayer()
{
    m_TotalApples = 5;
    m_IsAlive = true;
}

void Player::SetDebug(bool yesNo)
{
    p_Collider->SetDebug(yesNo);
}


void Player::Init()
{
}

void Player::Update(float deltaTime)
{
    
    p_PlayerTexture->Update(deltaTime);
    p_PlayerTexture->SetPosition(m_Position.x, m_Position.y);
    p_Collider->SetCenter(m_Position);
    p_Collider->Update(deltaTime);
}

void Player::Render()
{
    p_PlayerTexture->Draw();
    p_Collider->Render();
}