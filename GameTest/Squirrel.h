/****************************************************************************************
 * Script: Squirrel.h
 * Date: January 21, 2024
 * Description: This is the Squirrel Object.
 * TODO: Still needs work with Colliders.
 * Known Bugs:
 ****************************************************************************************/

#ifndef _SQUIRREL_H
#define _SQUIRREL_H

#include "Entity.h"

class Squirrel : public Entity
{
public:
    Squirrel();
    ~Squirrel();

    float GetTextureHeight();
    float GetTextureWidth();
    void GetApples();

    void SetAnimationType(AnimType animation);
    void SetTextureScale(float size);
    void SetDebug(bool yesNo);

    void ResetSquirrel();
    void PickUpApple();
    bool Collecting() const;
    void IsHit();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupCollider();
    void SetupTextures();
    void SetupAnimations();

private:
    CSimpleSprite* p_SquirrelTexture;

    float m_AnimationSpeed;
    float m_MoveSpeed;
    float m_Count;
    bool m_IsCollecting;
    bool m_PickUpApple;
    bool m_GetApple;
};
#endif // !_SQUIRREL_H