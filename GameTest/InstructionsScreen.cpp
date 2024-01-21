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

    std::string appleText = "You start with 5 Apples in your Tree.";
    std::string appleTextTwo = "You must collect the Apples from the Opposing Tree to win.";
    int textSize = appleText.size();
    char const* myApple = appleText.c_str();
    int textSizeTwo = appleTextTwo.size();
    char const* myAppleTwo = appleTextTwo.c_str();
    App::Print(HALF_WINDOW_WIDTH - (textSize * CHAR_WIDTH), currentY - TEXT_SPACING, myApple);
    App::Print(HALF_WINDOW_WIDTH - (textSizeTwo * CHAR_WIDTH), currentY - (TEXT_SPACING * 2), myAppleTwo);

}