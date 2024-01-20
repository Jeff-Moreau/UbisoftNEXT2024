#include "stdafx.h"
#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
    p_Selector = App::CreateSprite(".\\TestData\\Textures.bmp", 16, 16);
    p_Selector->SetFrame(240);
    p_Selector->SetPosition((APP_INIT_WINDOW_WIDTH * 0.5f) - TEXT_SPACING, (APP_INIT_WINDOW_HEIGHT * 0.5f));
    p_Selector->SetScale(1.0f);
}

MainMenuScreen::~MainMenuScreen()
{
}

void MainMenuScreen::Init()
{
}

void MainMenuScreen::Update(float deltaTime)
{
    float selectorX;
    float selectorY;
    p_Selector->GetPosition(selectorX, selectorY);
    float currentTime = 0.03f;
    if (App::IsKeyPressed('W') && currentTime == 0.03f)
    {
        currentTime = deltaTime;
        p_Selector->SetPosition(selectorX, selectorY + TEXT_SPACING);
    }
}

void MainMenuScreen::Render()
{
    p_Selector->Draw();
    OptionsList();
}

void MainMenuScreen::OptionsList()
{
    App::Print((APP_INIT_WINDOW_WIDTH * 0.5f), (APP_INIT_WINDOW_HEIGHT * 0.5f) + TEXT_SPACING, "1 PLAYER");
    App::Print((APP_INIT_WINDOW_WIDTH * 0.5f), (APP_INIT_WINDOW_HEIGHT * 0.5f), "2 PLAYER");
    App::Print((APP_INIT_WINDOW_WIDTH * 0.5f), (APP_INIT_WINDOW_HEIGHT * 0.5f) - TEXT_SPACING, "INSTRUCTIONS");
}