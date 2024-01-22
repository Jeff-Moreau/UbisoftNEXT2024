/****************************************************************************************
 * Script: MainMenu.h
 * Date: January 21, 2024
 * Description: MainMenu of the Game
 * TODO: There is no 2 Player Game needs to be coded in, it is Unfinished.
 * Known Bugs:
 ****************************************************************************************/

#ifndef _MAIN_MENU_SCREEN_H
#define _MAIN_MENU_SCREEN_H

#include "Screen.h"
#include "ScreenManager.h"

class MainMenuScreen : public Screen
{
private:
    const int OPTION_ONE_HEIGHT = 150;
    const int OPTION_TWO_HEIGHT = 125;
    const int OPTION_THREE_HEIGHT = 100;
    
public:
    MainMenuScreen();
    ~MainMenuScreen();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupSprites();
    void OptionsList();

private:
    CSimpleSprite* p_Selector;
    CSimpleSprite* p_BackDrop;
    
    bool m_IsKeyWPressed;
    bool m_IsKeySPressed;
    bool m_IsKeyReturnPressed;
};
#endif // !_MAIN_MENU_SCREEN_H