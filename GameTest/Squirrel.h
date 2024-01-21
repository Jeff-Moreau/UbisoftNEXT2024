#ifndef _SQUIRREL_H
#define _SQUIRREL_H

#include "Entity.h"

class Squirrel : public Entity
{
public:
    Squirrel();
    ~Squirrel();

    float GetTextureHeight();
    void SetAnimationType(AnimType animation);
    void SetTextureScale(float size);

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupAnimations();

private:
    CSimpleSprite* p_SquirrelTexture;

    float m_AnimationSpeed;
};
#endif // !_SQUIRREL_H