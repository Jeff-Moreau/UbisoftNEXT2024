/****************************************************************************************
 * Script: Player.h
 * Date: January 21, 2024
 * Description: This is the Player Object.
 * TODO: Collider Work.
 * Known Bugs:
 ****************************************************************************************/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Entity.h"
#include "Squirrel.h"

class Player : public Entity
{
public:
    Player();
    ~Player();

    float GetTextureHeight();
    int GetTotalApples() const;
    int GetObjectID() const;

    void SetTextureScale(float size);
    void SetAnimationType(AnimType animation);
    void SetTextureFrame(float frame);
    void SetTotalApples(int amount);
    void SetDebug(bool yesNo);

    void ResetPlayer();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupCollider();
    void SetupTextures();
    void SetupAnimations();

private:
    CSimpleSprite* p_PlayerTexture;

    float m_AnimationSpeed;
    int m_TotalApples;
    int m_Object;
};
#endif // !_PLAYER_H