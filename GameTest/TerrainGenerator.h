#ifndef _TERRAIN_GENERATOR_H
#define _TERRAIN_GENERATOR_H

#include "app\app.h"

class TerrainGenerator
{
private:
    const float TOTAL_SECTIONS = 32;
    const float TOTAL_START_SECTIONS = 6;
    const float TOTAL_ACORN_SECTIONS = 3;
    const float POINTS_PER_SECTION = 2;

    const int START_HEIGHT_MAX = 200;
    const int START_HEIGHT_LOW = 120;
    const int HEIGHT_MAX = 100;
    const int HEIGHT_LOW = 80;

    const int WINDOW_WIDTH = APP_INIT_WINDOW_WIDTH;
    const int WINDOW_HEIGHT = APP_INIT_WINDOW_HEIGHT;

public:
    TerrainGenerator();
    ~TerrainGenerator();
    
    void TerrainInit();
    void RandomizeTerrainHeight();
    void GenerateStartLocations();
    void GenerateAcornLocation();
    void GenerateTerrain();

    float GetTerrainHeightAt(float xLocation);

private:
    float m_SectionHeight[64];

    Utilities* p_Utilities;
    CSimpleSprite* testSprite;
};
#endif // !_TERRAIN_GENERATOR_H