#include "stdafx.h"
#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
    p_Terrain = new TerrainGenerator();
    p_Utilities = new Utilities();

    m_IsTarget = false;
    m_CanHitApples = true;
    m_Target = 0;
    m_Count = 0;
    m_TargetX = 0;
    m_TargetY = 0;

    SetupEntities();
    SetupTextures();
}

void PlayScreen::SetupEntities()
{
    p_LeftTree = new Tree();
    p_LeftTree->SetTextureFrame(p_Utilities->RandomNumber(0,2));
    p_LeftTree->SetPosition(96, p_Terrain->GetTerrainHeightAt(96) + p_LeftTree->GetTextureHeight() * 0.4f);

    p_RightTree = new Tree();
    p_RightTree->SetTextureFrame(p_Utilities->RandomNumber(3,5));
    p_RightTree->SetPosition((WINDOW_WIDTH - 96), p_Terrain->GetTerrainHeightAt((WINDOW_WIDTH - 96)) + (p_RightTree->GetTextureHeight() * 0.4f));
    
    p_PlayerSquirrel = new Squirrel();
    p_PlayerSquirrel->SetAnimationType(IDLE_RIGHT);
    p_PlayerSquirrel->SetPosition(p_LeftTree->GetPosition().x, p_Terrain->GetTerrainHeightAt(p_LeftTree->GetPosition().x) + p_PlayerSquirrel->GetTextureHeight());

    p_AISquirrel = new Squirrel();
    p_AISquirrel->SetAnimationType(IDLE_LEFT);
    p_AISquirrel->SetPosition(p_RightTree->GetPosition());
    
    p_Player = new Player();
    p_Player->SetPosition(p_LeftTree->GetPosition().x, p_LeftTree->GetPosition().y);
    p_Player->SetAnimationType(IDLE_RIGHT);

    p_AIPlayer = new AIPlayer();
    p_AIPlayer->SetPosition(p_RightTree->GetPosition().x, p_RightTree->GetPosition().y);
    p_AIPlayer->SetAnimationType(IDLE_LEFT);

    for (int i = 0; i < 10; i++)
    {
        p_Apple[i] = new Apple();
        p_Apple[i]->SetTextureScale(2);
    }

    for (int i = 0; i < 5; i++)
    {
        p_Apple[i]->SetPosition(p_LeftTree->GetPosition().x, (p_LeftTree->GetPosition().y + 170) - (i * 32));
    }

    for (int i = 5; i < 10; i++)
    {
        p_Apple[i]->SetPosition(p_RightTree->GetPosition().x, (p_RightTree->GetPosition().y + 325) - (i * 32));
    }

    p_AcornBullet = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_AcornBullet->SetFrame(2);
    p_AcornBullet->SetPosition(p_Player->GetPosition().x, p_Player->GetPosition().y - (p_Player->GetTextureHeight() / 2));
    p_AcornBullet->SetScale(1.0f);
}

void PlayScreen::SetupTextures()
{
    p_Sight = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_Sight->SetFrame(4);
    p_Sight->SetPosition(-10, -10);
    p_Sight->SetScale(1.0f);

    p_TargetLock = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_TargetLock->SetFrame(4);
    p_TargetLock->SetPosition(-20, -20);
    p_TargetLock->SetScale(2.0f);

    for (int i = 0; i < p_Player->GetTotalApples(); i++)
    {
        p_AppleTexture[i] = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
        p_AppleTexture[i]->SetFrame(1);
        p_AppleTexture[i]->SetPosition(-10, -10);
        p_AppleTexture[i]->SetScale(2.0f);
    }

    for (int i = 0; i < p_AIPlayer->GetTotalApples(); i++)
    {
        p_AppleTexture[i] = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
        p_AppleTexture[i]->SetFrame(1);
        p_AppleTexture[i]->SetPosition(-10, -10);
        p_AppleTexture[i]->SetScale(2.0f);
    }
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
    
    delete p_PlayerSquirrel;
    p_PlayerSquirrel = nullptr;

    delete p_AISquirrel;
    p_AISquirrel = nullptr;

    delete p_Player;
    p_Player = nullptr;

    delete p_AIPlayer;
    p_AIPlayer = nullptr;

    for (int i = 0; i < 10; i++)
    {
        delete p_Apple[i];
        p_Apple[i] = nullptr;

        delete p_AppleTexture[i];
        p_AppleTexture[i] = nullptr;
    }
}

void PlayScreen::Init()
{
}

void PlayScreen::Update(float deltaTime)
{
    m_Count += deltaTime / 1000;

    InputFunctions();

    p_Player->Update(deltaTime);
    p_AIPlayer->Update(deltaTime);
    p_LeftTree->Update(deltaTime);
    p_RightTree->Update(deltaTime);
    p_PlayerSquirrel->Update(deltaTime);

    for (int i = 0; i < 10; i++)
    {
        p_Apple[i]->TerrainHeight(p_Terrain->GetTerrainHeightAt(p_Apple[i]->GetPosition().x) + (p_Apple[i]->GetTextureHeight() * 0.5f));
        p_Apple[i]->Update(deltaTime);
    }

    CollisionChecks();

    UpdateScores(deltaTime);

    PlayerSquirrelActions();

    AISquirrelActions();

    if (p_Player->GetTotalApples() == 10 || p_AIPlayer->GetTotalApples() == 10)
    {
        p_Player->ResetPlayer();
        p_PlayerSquirrel->ResetSquirrel();
        p_AIPlayer->ResetPlayer();
        p_AISquirrel->ResetSquirrel();
        for (int i = 0; i < 10; i++)
        {
            p_Apple[i]->ResetApple();
        }
        for (int i = 0; i < 5; i++)
        {
            p_Apple[i]->SetPosition(p_LeftTree->GetPosition().x, (p_LeftTree->GetPosition().y + 170) - (i * 32));
        }

        for (int i = 5; i < 10; i++)
        {
            p_Apple[i]->SetPosition(p_RightTree->GetPosition().x, (p_RightTree->GetPosition().y + 325) - (i * 32));
        }
        ScreenManager::GetInstance().SetCurrentScreen(Results);
    }
}

void PlayScreen::AISquirrelActions()
{
    for (int i = 0; i < 5; i++)
    {
        if (p_AIPlayer->GetTotalApples() < 10 && p_Apple[i]->GetIsAlive() && p_Apple[i]->IsOnGround() && !p_AISquirrel->Collecting())
        {
            p_AISquirrel->GetApples();
        }
    }
}

void PlayScreen::PlayerSquirrelActions()
{
    for (int i = 5; i < 10; i++)
    {
        if (p_Player->GetTotalApples() < 10 && p_Apple[i]->GetIsAlive() && p_Apple[i]->IsOnGround() && !p_PlayerSquirrel->Collecting())
        {
            p_PlayerSquirrel->GetApples();
            p_PlayerSquirrel->SetPosition(p_PlayerSquirrel->GetPosition().x, p_Terrain->GetTerrainHeightAt(p_PlayerSquirrel->GetPosition().x + 32) + (p_PlayerSquirrel->GetTextureHeight()));
        }
    }
}

void PlayScreen::CollisionChecks()
{
    float acornX;
    float acornY;
    p_AcornBullet->GetPosition(acornX, acornY);

    if (acornY <= p_Terrain->GetTerrainHeightAt(acornX) || acornY > WINDOW_HEIGHT || acornX > WINDOW_WIDTH || acornX < (WINDOW_WIDTH - WINDOW_WIDTH))
    {
        p_AcornBullet->SetPosition(p_Player->GetPosition().x, p_Player->GetPosition().y - (p_Player->GetTextureHeight() / 2));
        m_IsTarget = false;
    }

    for (int i = 5; i < 10; i++)
    {
        if (m_CanHitApples && acornY <= (p_Apple[i]->GetPosition().y + (p_Apple[i]->GetTextureHeight())) &&
            acornY >= (p_Apple[i]->GetPosition().y - (p_Apple[i]->GetTextureHeight())) &&
            acornX >= p_Apple[i]->GetPosition().x)
        {
            p_Apple[i]->IsHit(true);
            p_AcornBullet->SetPosition(p_Player->GetPosition().x, p_Player->GetPosition().y - (p_Player->GetTextureHeight() / 2));
            m_CanHitApples = false;
            m_IsTarget = false;
            m_Target = i;
        }
    }

    if (p_Apple[m_Target]->GetIsAlive() && p_Apple[m_Target]->IsOnGround() && ((p_PlayerSquirrel->GetPosition().x + p_PlayerSquirrel->GetTextureWidth()) >= p_Apple[m_Target]->GetPosition().x - p_Apple[m_Target]->GetTextureWidth()))
    {
        p_PlayerSquirrel->PickUpApple();
        p_Player->SetTotalApples(1);
        p_AIPlayer->SetTotalApples(-1);
        p_Apple[m_Target]->SetIsAlive(false);
        //p_Apple[m_Target]->SetIsOnGround(false);
        m_CanHitApples = true;
        //p_Apple[m_Target]->SetIsAlive(false);
        m_Target = 0;
        p_PlayerSquirrel->ResetSquirrel();
        p_PlayerSquirrel->SetPosition(p_LeftTree->GetPosition().x, p_Terrain->GetTerrainHeightAt(p_LeftTree->GetPosition().x));
        p_PlayerSquirrel->SetAnimationType(IDLE_RIGHT);
    }
}

void PlayScreen::UpdateScores(float deltaTime)
{
    for (int i = 0; i < p_Player->GetTotalApples(); i++)
    {
        p_AppleTexture[i] = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
        p_AppleTexture[i]->SetFrame(1);
        p_AppleTexture[i]->SetScale(2.0f);
        p_AppleTexture[i]->Update(deltaTime);
    }

    for (int i = 0; i < p_AIPlayer->GetTotalApples(); i++)
    {
        p_AppleTexture[i] = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
        p_AppleTexture[i]->SetFrame(1);
        p_AppleTexture[i]->SetScale(2.0f);
        p_AppleTexture[i]->Update(deltaTime);
    }
}

void PlayScreen::InputFunctions()
{
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

    if (App::IsKeyPressed(VK_DOWN) && p_Player->GetTotalApples() > 0)
    {
        p_Player->SetTotalApples(-1);
    }

    if (App::IsKeyPressed(VK_UP) && p_Player->GetTotalApples() < 10)
    {
        p_Player->SetTotalApples(1);
    }
}

void PlayScreen::Render()
{
    DrawUI();

    p_Terrain->GenerateTerrain();
    p_LeftTree->Render();
    p_RightTree->Render();
    p_PlayerSquirrel->Render();
    p_Player->Render();
    p_AIPlayer->Render();

    for (int i = 0; i < 10; i++)
    {
        p_Apple[i]->Render();;
    }

    DrawScores();

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

void PlayScreen::DrawUI()
{
    App::Print(25, WINDOW_HEIGHT - 25, "Total Apples");
    App::Print(WINDOW_WIDTH - 125, WINDOW_HEIGHT - 25, "Total Apples");
}

void PlayScreen::DrawScores()
{
    for (int i = 0; i < p_Player->GetTotalApples(); i++)
    {
        p_AppleTexture[i]->SetPosition((i + 1) * 25, WINDOW_HEIGHT - 50);
        p_AppleTexture[i]->Draw();
    }

    for (int i = 0; i < p_AIPlayer->GetTotalApples(); i++)
    {
        p_AppleTexture[i]->SetPosition(WINDOW_WIDTH - ((i + 1) * 25), WINDOW_HEIGHT - 50);
        p_AppleTexture[i]->Draw();
    }
}
