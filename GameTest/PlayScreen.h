/****************************************************************************************
 * Script: PlayScreen.h
 * Date: January 21, 2024
 * Description: Main Gameplay screen
 * TODO: Collider work, Add Acorn Pile, add Walnut Drop
 * Known Bugs: Some colliders are buggy, squirrels acting off sometimes when
 *             Collecting Apples. AIPlayer not aiming properly at time.
 ****************************************************************************************/

#ifndef _PLAY_SCREEN_H
#define _PLAY_SCREEN_H

#include "TerrainGenerator.h"
#include "ScreenManager.h"
#include "AISquirrel.h"
#include "Squirrel.h"
#include "AIPlayer.h"
#include "Vector2.h"
#include "Screen.h"
#include "Player.h"
#include "Apple.h"
#include "Tree.h"

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
    void SetupTextures();

    void InputFunctions();
    void PlayerSquirrelActions();
    void AISquirrelActions();
    void CollisionChecks();
    void UpdateScores(float deltaTime);
    void CheckGameOver();

    void DrawUI();
    void DrawScores();
    
private:
    TerrainGenerator* p_Terrain;
    CSimpleSprite* p_AppleTexture[10];
    CSimpleSprite* p_AcornBullet[2];
    CSimpleSprite* p_TargetLock;
    CSimpleSprite* p_Sight;
    Squirrel* p_PlayerSquirrel;
    Utilities* p_Utilities;
    AISquirrel* p_AISquirrel;
    AIPlayer* p_AIPlayer;
    Player* p_Player;
    Apple* p_Apple[10];
    Tree* p_LeftTree;
    Tree* p_RightTree;

    bool m_IsDebugSet;
    bool m_IsKeyPPressed;
    bool m_IsKeyOPressed;
    bool m_IsKeyLPressed;
    bool m_PlayerCanShoot;
    bool m_CanHitApples;
    bool m_AICanHitApples;
    bool m_AICanShoot;
    int m_Target;
    int m_AITarget;
    float m_Count;
    float m_TargetX;
    float m_TargetY;
};
#endif // !_PLAY_SCREEN_H