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
    int GetObjectID();
    void SetTextureScale(float size);
    void SetAnimationType(AnimType animation);
    void SetTextureFrame(float frame);
    int GetTotalApples();
    void SetTotalApples(int amount);
    void ResetPlayer();
    void SetDebug(bool yesNo);
    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupAnimations();

private:
    CSimpleSprite* p_PlayerTexture;

    float m_AnimationSpeed;
    int m_Object;
    int m_TotalApples;
};
#endif // !_PLAYER_H