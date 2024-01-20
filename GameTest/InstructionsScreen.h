#ifndef _INSTRUCTIONS_SCREEN_H
#define _INSTRUCTIONS_SCREEN_H

#include "Screen.h"

class InstructionsScreen : public Screen
{
public:
    InstructionsScreen();
    ~InstructionsScreen();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;
};
#endif // !_INSTRUCTIONS_SCREEN_H