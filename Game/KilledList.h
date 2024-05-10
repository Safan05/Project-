#pragma once
#include"../DS/LinkedQueue.h"
#include <fstream>
class unit;
class KilledList :public LinkedQueue<unit*>
{
	int count;
	int EForces[3];    //ES, ET, EG
	int AForces[3];    //AS, AD, AM
public:
	KilledList();
	bool AddKilled(unit*&);
	void PrintKillled();
	void PrintReports(std::ofstream& f);
	int* GetEcount();
	int* GetAcount();
	int Ecount();
	int Acount();
	~KilledList();
};

