#include "stdafx.h"
#include "ResultsScreen.h"

ResultsScreen::ResultsScreen()
{
}

ResultsScreen::~ResultsScreen()
{
}

void ResultsScreen::Init()
{
}

void ResultsScreen::Update(float deltaTime)
{
    if (App::IsKeyPressed(VK_RETURN))
    {
       ScreenManager::GetInstance().SetCurrentScreen(MainMenu);
    }
}

void ResultsScreen::Render()
{
}