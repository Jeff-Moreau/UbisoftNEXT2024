#include "stdafx.h"
#include "Tree.h"

Tree::Tree()
{
    m_IsAlive = true;
    m_Position = Vector2(VectorZero);
    p_TreeTexture = App::CreateSprite(".\\TestData\\Trees.bmp", 3, 2);
    p_TreeTexture->SetFrame(0);
    p_TreeTexture->SetPosition(0, 0);
    p_TreeTexture->SetScale(1.0f);
}

Tree::~Tree()
{
    delete p_TreeTexture;
    p_TreeTexture = nullptr;
}

float Tree::GetTextureHeight()
{
    return p_TreeTexture->GetHeight();
}

void Tree::SetTextureScale(float size)
{
    p_TreeTexture->SetScale(size);
}

void Tree::SetTextureFrame(float frame)
{
    p_TreeTexture->SetFrame(frame);
}

void Tree::Init()
{
}

void Tree::Update(float deltaTime)
{
    p_TreeTexture->Update(deltaTime);
    p_TreeTexture->SetPosition(m_Position.x, m_Position.y);
}

void Tree::Render()
{
    if (m_IsAlive)
    {
        p_TreeTexture->Draw();
    }
}