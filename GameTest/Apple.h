/****************************************************************************************
 * Script: Apple.h
 * Date: January 21, 2024
 * Description: This is the Apple Object.
 * TODO: Get Colliders to function properly.
 * Known Bugs:
 ****************************************************************************************/

#ifndef _APPLE_H
#define  _APPLE_H

#include "Entity.h"

class Apple : public Entity
{
public:
    Apple();
    ~Apple();

    float GetTextureHeight();
    float GetTextureWidth();

    void SetTextureScale(float size);
    void SetTextureFrame(float frame);
    void SetIsOnGround(bool yesNo);
    void SetIsAlive(bool yesNo);
    void SetDebug(bool yesNo);

    void IsHit(bool yesNo);
    bool IsOnGround();
    void ResetApple();
    void TerrainHeight(float height);

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    void SetupCollider();
    void SetupTexture();

private:
    CSimpleSprite* p_AppleTexture;

    float m_TerrainHeight;
    bool m_IsOnGround;
    bool m_Falling;
};
#endif // !_APPLE_H