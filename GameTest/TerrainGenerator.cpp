#include "stdafx.h"
#include "TerrainGenerator.h"

TerrainGenerator::TerrainGenerator()
{
    p_Utilities = new Utilities();

    RandomizeTerrainHeight();
    GenerateStartLocations();
    GenerateAcornLocation();
}

TerrainGenerator::~TerrainGenerator()
{
    delete p_Utilities;
    p_Utilities = nullptr;
}

void TerrainGenerator::TerrainInit()
{
    testSprite = App::CreateSprite(".\\TestData\\Textures.bmp", 32, 32);
    testSprite->SetFrame(1);
    testSprite->SetScale(2.0f);
    App::Print(400, 400, "Hello");
}

void TerrainGenerator::RandomizeTerrainHeight()
{
    for (int i = 0; i < TOTAL_SECTIONS; i++)
    {
        float randomHeight = p_Utilities->RandomNumber(HEIGHT_LOW, HEIGHT_MAX);

        for (int j = 0; j < POINTS_PER_SECTION; j++)
        {
            m_SectionHeight[i + j] = randomHeight;
        }
        i++;
    }
}

void TerrainGenerator::GenerateStartLocations()
{
    float randomHeight = p_Utilities->RandomNumber(START_HEIGHT_LOW, START_HEIGHT_MAX);
    
    // Left side Starting Section
    for (int i = 0; i < TOTAL_START_SECTIONS; i++)
    {
        m_SectionHeight[i] = randomHeight;
    }

    randomHeight = p_Utilities->RandomNumber(START_HEIGHT_LOW, START_HEIGHT_MAX);
    int startingPoint = (TOTAL_SECTIONS - TOTAL_START_SECTIONS);
    
    // Right side Starting Section
    for (int i = startingPoint; i < TOTAL_SECTIONS+1; i++)
    {
        m_SectionHeight[i] = randomHeight;
    }
}

void TerrainGenerator::GenerateAcornLocation()
{
    float randomHeight = p_Utilities->RandomNumber(HEIGHT_LOW, START_HEIGHT_LOW);
    int offsetCenter = (TOTAL_SECTIONS / 2) - (TOTAL_ACORN_SECTIONS / 2);
    int sectionsAvailable = offsetCenter + TOTAL_ACORN_SECTIONS;

    for (int i = offsetCenter; i < sectionsAvailable; i++)
    {
        m_SectionHeight[i] = randomHeight;
    }
}

void TerrainGenerator::GenerateTerrain()
{
    float xLocation = (WINDOW_WIDTH / TOTAL_SECTIONS);

    for (int i = 0; i < TOTAL_SECTIONS + 1; i++)
    {
        App::DrawLine(i * xLocation, m_SectionHeight[i], (i + 1) * xLocation, m_SectionHeight[i + 1]);
        /*if (m_SectionHeight[i] > 100)
        {
            testSprite->SetPosition(i * xLocation, m_SectionHeight[i]);
            testSprite->Draw();
        }*/
    }
}

float TerrainGenerator::GetTerrainHeightAt(float xLocation)
{
    int terrainHeight = (xLocation * TOTAL_SECTIONS) / WINDOW_WIDTH;

    return m_SectionHeight[terrainHeight];
}