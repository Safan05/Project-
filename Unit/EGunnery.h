#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class EGunnery :public unit
{
public:
    EGunnery(double H, int P, int AC, int T);
    bool attack(Game* GPtr);
};