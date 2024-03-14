#pragma once
#include"Type.h"
class unit
{
private:
	int id;
	int JoinTime;
	int Health;
	int Power;
	int AttackCapacity;
	int Type;
public:
	unit(int I,int JT,int H,int P,int AC,int T);
	bool is_killed();
};

