/****************************************************************************************
 * Script: AISquirrel.h
 * Date: January 21, 2024
 * Description: This is the AISquirrel Object.
 * TODO: Collider Work.
 * Known Bugs:
 ****************************************************************************************/

#ifndef _AISQUIRREL_H
#define _AISQUIRREL_H

#include "Entity.h"

class AISquirrel : public Entity
{
public:
    AISquirrel();
    ~AISquirrel();

    float GetTextureHeight();
    float GetTextureWidth();
    void GetApples();

    void SetAnimationType(AnimType animation);
    void SetTextureScale(float size);
    void SetDebug(bool yesNo);

    void ResetSquirrel();
    void PickUpApple();
    bool Collecting();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupColliders();
    void SetupTextures();
    void SetupAnimations();

private:
    CSimpleSprite* p_AISquirrelTexture;

    float m_AnimationSpeed;
    float m_Count;
    bool m_GetApple;
    bool m_PickUpApple;
    bool m_IsCollecting;
    float m_MoveSpeed;
};
#endif // !_AISQUIRREL_H