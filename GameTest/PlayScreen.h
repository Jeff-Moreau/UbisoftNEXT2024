#ifndef _PLAY_SCREEN_H
#define _PLAY_SCREEN_H

#include "Screen.h"

class PlayScreen : public Screen
{
public:
    PlayScreen();
    ~PlayScreen();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;
};
#endif // !_PLAY_SCREEN_H