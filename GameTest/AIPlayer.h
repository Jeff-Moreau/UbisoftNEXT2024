/****************************************************************************************
 * Script: AIPlayer.h
 * Date: January 21, 2024
 * Description: This is the AIPlayer Object.
 * TODO: Collider Work. more work on the AI system
 * Known Bugs:
 ****************************************************************************************/

#ifndef _AIPLAYER_H
#define _AIPLAYER_H

#include "Entity.h"

class AIPlayer : public Entity
{
public:
    AIPlayer();
    ~AIPlayer();

    float GetTextureHeight();
    int GetTotalApples();
    int GetObjectID();

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
    void SetupAnimations();
    void SetupCollider();
    void SetupTextures();

private:
    CSimpleSprite* p_AIPlayerTexture;

    float m_AnimationSpeed;
    int m_TotalApples;
    int m_Object;
};
#endif // !_AIPLAYER_H