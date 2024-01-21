#ifndef _AIPLAYER_H
#define _AIPLAYER_H

#include "Entity.h"

class AIPlayer : public Entity
{
public:
    AIPlayer();
    ~AIPlayer();

    float GetTextureHeight();
    int GetObjectID();
    void SetTextureScale(float size);
    void SetAnimationType(AnimType animation);
    void SetTextureFrame(float frame);
    int GetTotalApples();
    void ResetPlayer();
    void SetDebug(bool yesNo);
    void SetTotalApples(int amount);
    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupAnimations();

private:
    CSimpleSprite* p_AIPlayerTexture;

    float m_AnimationSpeed;
    int m_Object;
    int m_TotalApples;
};
#endif // !_AIPLAYER_H