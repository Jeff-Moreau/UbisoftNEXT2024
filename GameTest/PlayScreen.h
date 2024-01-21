#ifndef _PLAY_SCREEN_H
#define _PLAY_SCREEN_H

#include "Screen.h"
#include "Vector2.h"
#include "TerrainGenerator.h"
#include "Squirrel.h"
#include "Tree.h"
#include "Player.h"
#include "Apple.h"

class PlayScreen : public Screen
{
public:
    PlayScreen();
    ~PlayScreen();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupEntities();
    
private:
    TerrainGenerator* p_Terrain;
    CSimpleSprite* p_AcornBullet;
    CSimpleSprite* p_TargetLock;
    CSimpleSprite* p_Sight;
    CSimpleSprite* p_AppleTexture[10];
    Utilities* p_Utilities;
    Apple* p_Apple[10];
    Squirrel* p_Squirrel;
    Player* p_Player;
    Tree* p_LeftTree;
    Tree* p_RightTree;

    char const* m_NewX;
    bool m_IsTarget;
    float m_TargetX;
    float m_TargetY;
    float m_Count;
};
#endif // !_PLAY_SCREEN_H