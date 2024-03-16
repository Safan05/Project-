#pragma once
#ifndef UNIT
#define UNIT
#include"Type.h"
//#include"Game/Game.h"
class Game;
class unit
{
private:
	int id;
	int JoinTime;
	float Health;
	int Power;
	int AttackCapacity;
	int Type;
public:
	unit(int H,int P,int AC,int T);
	bool is_killed();
	bool operator>(const unit& a) const;
	virtual bool attack(Game* GPtr) = 0;
	int GetType();
	void SetId(int I);
	void SetJoin(int J);
	int GetAC();
	int GetPow();
	int GetHealth();
	void DecHealth(int h);
	void PrintUnit();  //to be replaced with operatorover.??
};
#endif
