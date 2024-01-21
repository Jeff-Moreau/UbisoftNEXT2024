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
    void CollisionChecks();
    void UpdateScores(float deltaTime);
    void InputFunctions();
    void Render() override;

    void DrawUI();

    void DrawScores();

private:
    void SetupEntities();

    void SetupTextures();
    
private:
    TerrainGenerator* p_Terrain;
    CSimpleSprite* p_AcornBullet;
    CSimpleSprite* p_TargetLock;
    CSimpleSprite* p_Sight;
    CSimpleSprite* p_AppleTexture[10];
    Utilities* p_Utilities;
    Apple* p_Apple[10];
    Squirrel* p_PlayerSquirrel;
    Squirrel* p_AISquirrel;
    Player* p_Player;
    Player* p_AIPlayer;
    Tree* p_LeftTree;
    Tree* p_RightTree;

    bool m_IsTarget;
    bool m_CanHitApples;
    int m_Target;
    float m_Count;
    float m_TargetX;
    float m_TargetY;
};
#endif // !_PLAY_SCREEN_H