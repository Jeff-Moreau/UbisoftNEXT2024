/****************************************************************************************
 * Script: ScreenManager.h
 * Date: January 21, 2024
 * Description: Manages the changing between screens for the prorgam
 * TODO:
 * Known Bugs:
 ****************************************************************************************/

#ifndef _SCREEN_MANAGER_H
#define _SCREEN_MANAGER_H

#include <vector>

#include "InstructionsScreen.h"
#include "MainMenuScreen.h"
#include "ResultsScreen.h"
#include "PlayScreen.h"
#include "Screen.h"

enum Screens
{
    MainMenu,
    Play,
    Results,
    Instructions
};

class ScreenManager
{
public:
    static ScreenManager &ScreenManager::GetInstance();

    ScreenManager();
    ~ScreenManager();

    Screen* GetScreen(Screens screen);
    void SetCurrentScreen(Screens screen);
    
    void Init();
    void Update(float deltaTime);
    void Render();

private:
    std::vector<Screen*> p_Screens;
    Screens m_CurrentScreen;
};
#endif // !_SCREEN_MANAGER_H