/****************************************************************************************
 * Script: ResultsScreen.cpp
 * Date: January 21, 2024
 * Description: Gameover screen and show results of the match
 * TODO: needs more work
 * Known Bugs:
 ****************************************************************************************/

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