#ifndef _PLAY_SCREEN_H
#define _PLAY_SCREEN_H

#include "Screen.h"
#include "Vector2.h"
#include "TerrainGenerator.h"
#include "Squirrel.h"
#include "AISquirrel.h"
#include "Tree.h"
#include "Player.h"
#include "AIPlayer.h"
#include "Apple.h"
#include "ScreenManager.h"

class PlayScreen : public Screen
{
public:
    PlayScreen();
    ~PlayScreen();

    void Init() override;
    void Update(float deltaTime) override;
    void AISquirrelActions();
    void PlayerSquirrelActions();
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
    CSimpleSprite* p_AcornBullet[2];
    CSimpleSprite* p_TargetLock;
    CSimpleSprite* p_Sight;
    CSimpleSprite* p_AppleTexture[10];
    Utilities* p_Utilities;
    Apple* p_Apple[10];
    Squirrel* p_PlayerSquirrel;
    AISquirrel* p_AISquirrel;
    Player* p_Player;
    AIPlayer* p_AIPlayer;
    Tree* p_LeftTree;
    Tree* p_RightTree;

    bool m_IsDebugSet;
    bool m_IsKeyPPressed;
    bool m_IsKeyOPressed;
    bool m_IsKeyLPressed;
    bool m_IsTarget;
    bool m_CanHitApples;
    bool m_AICanShoot;
    int m_Target;
    float m_Count;
    float m_TargetX;
    float m_TargetY;
};
#endif // !_PLAY_SCREEN_H