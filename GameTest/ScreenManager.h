#ifndef _SCREEN_MANAGER_H
#define _SCREEN_MANAGER_H

#include <vector>
#include "Screen.h"
#include "MainMenuScreen.h"
#include "PlayScreen.h"
#include "ResultsScreen.h"
#include "InstructionsScreen.h"

class ScreenManager
{
public:
    enum Screens
    {
        MainMenu,
        Play,
        Results,
        Instructions
    };

public:
    static ScreenManager &ScreenManager::GetInstance();
    ScreenManager();
    ~ScreenManager();

    void SetCurrentScreen(Screens screen);
    Screen* GetScreen(Screens screen);
    
    void Init();
    void Update(float deltaTime);
    void Render();

private:
    std::vector<Screen*> p_Screens;
    Screens m_CurrentScreen;
};
#endif // !_SCREEN_MANAGER_H