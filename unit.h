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
	unit(int H,int P,int AC,int T);
	bool is_killed();
	int GetType();
	void SetId(int I);
	void SetJoin(int J);
};

