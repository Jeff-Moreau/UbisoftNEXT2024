/****************************************************************************************
 * Script: InstructionScreen.cpp
 * Date: January 21, 2024
 * Description: Instructions for game play.
 * TODO: Unfinished, needs for information on how to play the game.
 * Known Bugs:
 ****************************************************************************************/

#include "stdafx.h"
#include "InstructionsScreen.h"

InstructionsScreen::InstructionsScreen()
{
    SetupSprites();
}

void InstructionsScreen::SetupSprites()
{
    p_Apple = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    p_Apple->SetFrame(1);
    p_Apple->SetPosition(HALF_WINDOW_WIDTH, HALF_WINDOW_HEIGHT);
    p_Apple->SetScale(1.0f);
}

InstructionsScreen::~InstructionsScreen()
{
    delete p_Apple;
    p_Apple = nullptr;
}

void InstructionsScreen::Init()
{
}

void InstructionsScreen::Update(float deltaTime)
{
    if (App::IsKeyPressed(VK_SPACE))
    {
        ScreenManager::GetInstance().SetCurrentScreen(MainMenu);
    }
}

void InstructionsScreen::Render()
{
    float currentX;
    float currentY;
    p_Apple->GetPosition(currentX, currentY);
    p_Apple->Draw();

    std::string appleText = "Use W, S to scroll up and down the menu's";
    std::string appleTextTwo = "Press ENTER key to select an option. Press SPACEBAR to get back to MainMenu";
    int textSize = appleText.size();
    char const* myApple = appleText.c_str();
    int textSizeTwo = appleTextTwo.size();
    char const* myAppleTwo = appleTextTwo.c_str();
    App::Print(HALF_WINDOW_WIDTH - (textSize * CHAR_WIDTH), currentY - TEXT_SPACING, myApple);
    App::Print(HALF_WINDOW_WIDTH - (textSizeTwo * CHAR_WIDTH), currentY - (TEXT_SPACING * 2), myAppleTwo);
    App::Print(HALF_WINDOW_WIDTH, 700, "Hold down RIGHT MOUSE button to AIM");
    App::Print(HALF_WINDOW_WIDTH, 675, "Click LEFT MOUSE button to shoot.");
    App::Print(HALF_WINDOW_WIDTH, 650, "Try to knock out the Apples in the other tree.");
    App::Print(HALF_WINDOW_WIDTH, 625, "You can shoot the other Teams Squirrel that is running");
    App::Print(HALF_WINDOW_WIDTH, 600, "This will prevent them from getting a shot down Apple.");
    App::Print(HALF_WINDOW_WIDTH, 575, "Collect 10 Apples to win.");
}