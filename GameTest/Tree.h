#ifndef _TREE_H
#define _TREE_H

#include "Entity.h"

class Tree : public Entity
{
public:
    Tree();
    ~Tree();

    float GetTextureHeight();
    void SetTextureScale(float size);
    void SetTextureFrame(float frame);

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;

private:
    CSimpleSprite* p_TreeTexture;
};
#endif // !_TREE_H