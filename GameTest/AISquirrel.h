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
    void SetAnimationType(AnimType animation);
    void SetTextureScale(float size);
    void GetApples();
    void PickUpApple();
    bool Collecting();
    void ResetSquirrel();
    void SetDebug(bool yesNo);
    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
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