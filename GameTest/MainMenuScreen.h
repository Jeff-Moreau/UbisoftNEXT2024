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
    
    int m_IsKeyWPressed;
    int m_IsKeySPressed;
};
#endif // !_MAIN_MENU_SCREEN_H