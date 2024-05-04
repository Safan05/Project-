#pragma once
#ifndef UNIT
#define UNIT
#include"../DS/LinkedQueue.h"
#include<fstream>
class Game;
class unit
{
private:
	int id;
	int JoinTime;
	int ImpTime[3]; //[0] Tj,[1]Ta,[2],Td
	double Health;
	double InitialHealth;
	int Power;
	int AttackCapacity;
	int Type;
	bool Isattacked;
	LinkedQueue<int> attacked_IDs;
public:
	unit(double H, int P, int AC, int T);
	bool is_killed();
	bool operator>(const unit& a) const;
	double GetHPercent();
	virtual bool attack(Game* const & GPtr) = 0;
	int GetType();
	void SetId(int I);
	int GetId();
	void SetJoin(int J);
	int GetAC();
	int GetPow();
	int GetHealth();
	LinkedQueue<int>& GetattackedIDs();
	void DecHealth(double h);
	void IncHealth(double h);
	void SetAttacked(bool a);
	bool Wasattacked();
	void SetTa(int t);
	void SetTd(int t);
	void DeathReport(std::ofstream& wr);
	void PrintUnit();
	virtual void PrintAttacked() = 0;
};
#endif
