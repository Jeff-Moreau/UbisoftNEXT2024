#ifndef _APPLE_H
#define  _APPLE_H

#include "Entity.h"

class Apple : public Entity
{
public:
    Apple();
    ~Apple();

    float GetTextureHeight();
    void SetTextureScale(float size);
    void SetTextureFrame(float frame);
    bool IsOnGround();
    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    CSimpleSprite* p_AppleTexture;
    bool m_IsOnGround;
};
#endif // !_APPLE_H