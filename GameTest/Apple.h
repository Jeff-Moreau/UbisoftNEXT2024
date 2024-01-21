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
    bool IsOnGround();
    void SetIsOnGround(bool yesNo);
    void SetIsAlive(bool yesNo);
    void ResetApple();
    void TerrainHeight(float height);
    void IsHit(bool yesNo);
    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    CSimpleSprite* p_AppleTexture;
    bool m_IsOnGround;
    bool m_Falling;
    float m_TerrainHeight;
};
#endif // !_APPLE_H