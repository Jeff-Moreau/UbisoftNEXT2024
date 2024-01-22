/****************************************************************************************
 * Script: MainMenu.cpp
 * Date: January 21, 2024
 * Description: MainMenu of the Game
 * TODO: There is no 2 Player Game needs to be coded in, it is Unfinished.
 * Known Bugs:
 ****************************************************************************************/

#include "stdafx.h"
#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
    SetupSprites();

    m_IsKeyWPressed = false;
    m_IsKeySPressed = false;
    m_IsKeyReturnPressed = false;
}

void MainMenuScreen::SetupSprites()
{
    p_Selector = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_Selector->SetFrame(0);
    p_Selector->SetPosition(HALF_WINDOW_WIDTH - TEXT_SPACING, OPTION_ONE_HEIGHT + (p_Selector->GetHeight() * 0.5f));
    p_Selector->SetScale(1.0f);

    p_BackDrop = App::CreateSprite(".\\TestData\\Ubisoft-Toronto-NEXT.bmp", 1, 1);
    p_BackDrop->SetPosition(HALF_WINDOW_WIDTH, HALF_WINDOW_HEIGHT);
    p_BackDrop->SetScale(1.0f);
}

MainMenuScreen::~MainMenuScreen()
{
    delete p_Selector;
    p_Selector = nullptr;

    delete p_BackDrop;
    p_BackDrop = nullptr;
}

void MainMenuScreen::Init()
{
}

void MainMenuScreen::Update(float deltaTime)
{
    float currentX;
    float currentY;
    p_Selector->GetPosition(currentX, currentY);

    if (App::IsKeyPressed('W') && currentY < OPTION_ONE_HEIGHT && !m_IsKeyWPressed)
    {
        p_Selector->SetPosition(currentX, currentY + TEXT_SPACING);
        m_IsKeyWPressed = true;
        App::PlaySound(".\\TestData\\Test.wav");
    }
    else if ((GetAsyncKeyState('W') & 0x8000) == 0)
    {
        m_IsKeyWPressed = false;
    }

    if (App::IsKeyPressed('S') && currentY > OPTION_THREE_HEIGHT + (p_Selector->GetHeight() * 0.5f) && !m_IsKeySPressed)
    {
        p_Selector->SetPosition(currentX, currentY - TEXT_SPACING);
        m_IsKeySPressed = true;
        App::PlaySound(".\\TestData\\Test.wav");
    }
    else if ((GetAsyncKeyState('S') & 0x8000) == 0)
    {
        m_IsKeySPressed = false;
    }

    if (App::IsKeyPressed(VK_RETURN) && !m_IsKeyReturnPressed)
    {
        if (currentY == OPTION_ONE_HEIGHT + (p_Selector->GetHeight() * 0.5f))
        {
            m_IsKeyReturnPressed = true;
            ScreenManager::GetInstance().SetCurrentScreen(Play);
        }
        else if (currentY == OPTION_TWO_HEIGHT + (p_Selector->GetHeight() * 0.5f))
        {
            m_IsKeyReturnPressed = true;
            ScreenManager::GetInstance().SetCurrentScreen(Play);
        }
        else if (currentY == OPTION_THREE_HEIGHT + (p_Selector->GetHeight() * 0.5f))
        {
            m_IsKeyReturnPressed = true;
            ScreenManager::GetInstance().SetCurrentScreen(Instructions);
        }
    }
    else if ((GetAsyncKeyState(VK_RETURN) & 0x8000) == 0)
    {
        m_IsKeyReturnPressed = false;
    }
}

void MainMenuScreen::Render()
{
    p_BackDrop->Draw();
    p_Selector->Draw();

    OptionsList();
}

void MainMenuScreen::OptionsList()
{
    App::Print(HALF_WINDOW_WIDTH, OPTION_ONE_HEIGHT, "1 PLAYER");
    App::Print(HALF_WINDOW_WIDTH, OPTION_TWO_HEIGHT, "2 PLAYER");
    App::Print(HALF_WINDOW_WIDTH, OPTION_THREE_HEIGHT, "INSTRUCTIONS");
    App::Print(HALF_WINDOW_WIDTH, OPTION_THREE_HEIGHT - 50, "PRESS W or S for up and down, press ENTER to select");
    App::Print(HALF_WINDOW_WIDTH, OPTION_THREE_HEIGHT - 75, "2 PLAYER just gives you 1 PLAYER right now");
}