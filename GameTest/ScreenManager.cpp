#include "stdafx.h"
#include "ScreenManager.h"

ScreenManager &ScreenManager::GetInstance()
{
    static ScreenManager screenManager;
    return screenManager;
}

ScreenManager::ScreenManager()
{
    p_Screens.push_back(new MainMenuScreen());
    p_Screens.push_back(new PlayScreen());
    p_Screens.push_back(new ResultsScreen());
    p_Screens.push_back(new InstructionsScreen());
    m_CurrentScreen = MainMenu;
}

ScreenManager::~ScreenManager()
{
    for (int i = 0; i < p_Screens.size(); i++)
    {
        delete p_Screens[i];
        p_Screens[i] = nullptr;
    }
}

void ScreenManager::SetCurrentScreen(Screens screen)
{
    m_CurrentScreen = screen;
}

Screen* ScreenManager::GetScreen(Screens screen)
{
    return p_Screens[(int)screen];
}

void ScreenManager::Init()
{
}

void ScreenManager::Update(float deltaTime)
{
    p_Screens[m_CurrentScreen]->Update(deltaTime);
}

void ScreenManager::Render()
{
    p_Screens[m_CurrentScreen]->Render();
}