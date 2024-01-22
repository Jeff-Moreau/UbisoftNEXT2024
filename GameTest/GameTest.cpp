/****************************************************************************************
 * Script: GameTest.cpp
 * Date: January 21, 2024
 * Description: This is the Main functions for the program.
 * TODO:
 * Known Bugs:
 ****************************************************************************************/
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
#include "TerrainGenerator.h"
#include "ScreenManager.h"

ScreenManager* p_ScreenManager;

void Init()
{
	ScreenManager::GetInstance().Init();
}

void Update(float deltaTime)
{
	ScreenManager::GetInstance().Update(deltaTime);
}

void Render()
{	
	ScreenManager::GetInstance().Render();

}

void Shutdown()
{	

}