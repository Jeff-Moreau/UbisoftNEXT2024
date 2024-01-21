#include "stdafx.h"
#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
    p_Terrain = new TerrainGenerator();
    p_Utilities = new Utilities();
    m_IsTarget = false;
    m_TargetX = 0;
    m_TargetY = 0;
    m_Count = 0;
    m_NewX = 0;

    SetupEntities();
}

void PlayScreen::SetupEntities()
{
    p_Sight = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_Sight->SetFrame(4);
    p_Sight->SetPosition(-10, -10);
    p_Sight->SetScale(1.0f);

    p_TargetLock = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_TargetLock->SetFrame(4);
    p_TargetLock->SetPosition(-20, -20);
    p_TargetLock->SetScale(2.0f);

    p_Squirrel = new Squirrel();
    
    p_LeftTree = new Tree();
    p_LeftTree->SetTextureFrame(p_Utilities->RandomNumber(0,2));
    p_LeftTree->SetPosition(96, p_Terrain->GetTerrainHeightAt(96) + p_LeftTree->GetTextureHeight() * 0.4f);

    p_RightTree = new Tree();
    p_RightTree->SetTextureFrame(p_Utilities->RandomNumber(3,5));
    p_RightTree->SetPosition((WINDOW_WIDTH - 96), p_Terrain->GetTerrainHeightAt((WINDOW_WIDTH - 96)) + (p_RightTree->GetTextureHeight() * 0.4f));

    p_Player = new Player();
    p_Player->SetPosition(p_LeftTree->GetPosition().x, p_LeftTree->GetPosition().y);
    p_Player->SetAnimationType(IDLE_RIGHT);

    for (int i = 0; i < 10; i++)
    {
        p_Apple[i] = new Apple();
        p_Apple[i]->SetTextureScale(2);
    }

    for (int i = 0; i < p_Player->GetTotalApples(); i++)
    {
        p_AppleTexture[i] = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
        p_AppleTexture[i]->SetFrame(1);
        p_AppleTexture[i]->SetPosition(-10, -10);
        p_AppleTexture[i]->SetScale(2.0f);
    }

    p_AcornBullet = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_AcornBullet->SetFrame(2);
    p_AcornBullet->SetPosition(p_Player->GetPosition().x, p_Player->GetPosition().y - (p_Player->GetTextureHeight() / 2));
    p_AcornBullet->SetScale(1.0f);
}

PlayScreen::~PlayScreen()
{
    delete p_Terrain;
    p_Terrain = nullptr;

    delete p_Sight;
    p_Sight = nullptr;

    delete p_TargetLock;
    p_TargetLock = nullptr;
    
    delete p_AcornBullet;
    p_AcornBullet = nullptr;

    delete p_Utilities;
    p_Utilities = nullptr;

    delete p_LeftTree;
    p_LeftTree = nullptr;

    delete p_RightTree;
    p_RightTree = nullptr;
    
    delete p_Squirrel;
    p_Squirrel = nullptr;

    delete p_Player;
    p_Player = nullptr;
}

void PlayScreen::Init()
{
}

void PlayScreen::Update(float deltaTime)
{
    if (App::IsKeyPressed(VK_DOWN) && p_Player->GetTotalApples() > 0)
    {
        p_Player->SetTotalApples(-1);
    }

    if (App::IsKeyPressed(VK_UP) && p_Player->GetTotalApples() < 10)
    {
        p_Player->SetTotalApples(1);
    }
    m_Count += (deltaTime / 1000);

    if (m_Count > 5)
    {
        p_Squirrel->SetAnimationType(MOVE_RIGHT);
        p_Squirrel->SetPosition(p_Squirrel->GetPosition().x + 0.7f, p_Terrain->GetTerrainHeightAt(p_Squirrel->GetPosition().x + 32) + (p_Squirrel->GetTextureHeight() * 0.5f));
    }
    p_Squirrel->Update(deltaTime);
    p_Player->Update(deltaTime);
    for (int i = 0; i < p_Player->GetTotalApples(); i++)
    {
        p_AppleTexture[i] = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
        p_AppleTexture[i]->SetFrame(1);
        p_AppleTexture[i]->SetScale(2.0f);
        p_AppleTexture[i]->Update(deltaTime);
    }
    p_LeftTree->Update(deltaTime);
    p_RightTree->Update(deltaTime);

    for (int i = 0; i < 5; i++)
    {
        p_Apple[i]->SetPosition(p_LeftTree->GetPosition().x, (p_LeftTree->GetPosition().y + 170) - (i * 32));
    }

    for (int i = 0; i < 10; i++)
    {
        p_Apple[i]->Update(deltaTime);
    }

    for (int i = 0; i < 10; i++)
    {
        if (p_Player->GetTotalApples() < 10 && p_Apple[i]->IsOnGround())
        {
            p_Squirrel->SetPosition(p_Apple[i]->GetPosition().x + 0.7f, p_Terrain->GetTerrainHeightAt(p_Squirrel->GetPosition().x + 32) + (p_Squirrel->GetTextureHeight() * 0.5f));
        }
    }

    float currentX;
    float currentY;
    App::GetMousePos(currentX, currentY);

    if (App::IsKeyPressed(VK_RBUTTON) && !m_IsTarget)
    {
        p_Sight->SetPosition(currentX, currentY);

        if (App::IsKeyPressed(VK_LBUTTON))
        {
            m_IsTarget = true;
            m_TargetX = currentX;
            m_TargetY = currentY;
            p_TargetLock->SetPosition(currentX, currentY);
        }
    }

    float acornX;
    float acornY;
    p_AcornBullet->GetPosition(acornX, acornY);

    if (acornY <= p_Terrain->GetTerrainHeightAt(acornX) || acornY > WINDOW_HEIGHT || acornX > WINDOW_WIDTH || acornX < (WINDOW_WIDTH - WINDOW_WIDTH))
    {
        p_AcornBullet->SetPosition(p_Player->GetPosition().x, p_Player->GetPosition().y - (p_Player->GetTextureHeight() / 2));
        m_IsTarget = false;
    }
}


void PlayScreen::Render()
{
    App::Print(25, WINDOW_HEIGHT - 25, "Total Apples");
    App::Print(WINDOW_WIDTH - 125, WINDOW_HEIGHT - 25, "Total Apples");
    p_Terrain->GenerateTerrain();
    p_LeftTree->Render();
    p_RightTree->Render();
    p_Squirrel->Render();
    p_Player->Render();

    for (int i = 0; i < 10; i++)
    {
        p_Apple[i]->Render();;
    }

    for (int i = 0; i < p_Player->GetTotalApples(); i++)
    {
        p_AppleTexture[i]->SetPosition((i + 1) * 25, WINDOW_HEIGHT - 50);
        p_AppleTexture[i]->Draw();
    }

    p_Sight->Draw();
    
    if (m_IsTarget)
    {
        float currentX;
        float currentY;
        p_AcornBullet->GetPosition(currentX, currentY);
        currentX += (m_TargetX - p_Player->GetPosition().x) / 150;
        currentY += (m_TargetY - p_Player->GetPosition().y - (p_Player->GetTextureHeight() / 2)) / 150;
        p_AcornBullet->SetAngle(p_Utilities->RandomNumber(170, 230));
        p_AcornBullet->SetPosition(currentX, currentY);
        p_AcornBullet->Draw();
        p_TargetLock->Draw();
        p_Sight->SetPosition(-10, -10);
        App::DrawLine(p_Player->GetPosition().x, p_Player->GetPosition().y - (p_Player->GetTextureHeight() / 2), m_TargetX, m_TargetY, 255, 0, 0);
    }
}