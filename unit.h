#pragma once
#ifndef UNIT
#define UNIT
#include"Type.h"
#include<fstream>
class Game;
class unit
{
private:
	int id;
	int JoinTime;
	int ImpTime[3]; //[0] Tj,[1]Ta,[2],Td
	double Health;
	int Power;
	double AttackCapacity;
	int Type;
	bool Isattacked;
public:
	unit(double H, int P, int AC, int T);
	bool is_killed();
	bool operator>(const unit& a) const;
	virtual int attack(Game* GPtr) = 0;
	int GetType();
	void SetId(int I);
	int GetId();
	void SetJoin(int J);
	int GetAC();
	int GetPow();
	int GetHealth();
	void DecHealth(double h);
	void SetAttacked(bool a);
	bool Wasattacked();
	void SetTa(int t);
	void SetTd(int t);
	void DeathReport(std::ofstream& wr);
	void PrintUnit();
};
#endif
