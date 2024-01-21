#ifndef _RESULTS_SCREEN_H
#define _RESULTS_SCREEN_H

#include "Screen.h"
#include "ScreenManager.h"

class ResultsScreen : public Screen
{
public:
    ResultsScreen();
    ~ResultsScreen();

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;
};
#endif // !_RESULTS_SCREEN_H