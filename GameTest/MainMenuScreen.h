#ifndef _MAIN_MENU_SCREEN_H
#define _MAIN_MENU_SCREEN_H

#include "Screen.h"

class MainMenuScreen : public Screen
{
public:
    MainMenuScreen();
    ~MainMenuScreen();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void OptionsList();

private:
    CSimpleSprite* p_Selector;
};
#endif // !_MAIN_MENU_SCREEN_H