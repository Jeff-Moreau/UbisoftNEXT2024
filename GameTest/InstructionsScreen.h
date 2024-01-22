/****************************************************************************************
 * Script: InstructionScreen.h
 * Date: January 21, 2024
 * Description: Instructions for game play.
 * TODO: Unfinished, needs for information on how to play the game.
 * Known Bugs:
 ****************************************************************************************/

#ifndef _INSTRUCTIONS_SCREEN_H
#define _INSTRUCTIONS_SCREEN_H

#include "Screen.h"
#include "ScreenManager.h"

class InstructionsScreen : public Screen
{
public:
    InstructionsScreen();
    ~InstructionsScreen();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupSprites();

private:
    CSimpleSprite* p_Apple;
};
#endif // !_INSTRUCTIONS_SCREEN_H