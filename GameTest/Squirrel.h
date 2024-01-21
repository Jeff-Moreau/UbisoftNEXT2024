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
    void SetAnimationType(AnimType animation);
    void SetTextureScale(float size);
    void GetApples();
    void PickUpApple();
    bool Collecting();
    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupAnimations();

private:
    CSimpleSprite* p_SquirrelTexture;

    float m_AnimationSpeed;
    float m_Count;
    bool m_GetApple;
    bool m_PickUpApple;
    bool m_IsCollecting;
    
};
#endif // !_SQUIRREL_H