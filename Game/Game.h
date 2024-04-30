#pragma once
#include "RandGen.h"
#include"..\EarthForces\EarthArmy.h"
#include"..\Alien Forces\AlienArmy.h"
class Game
{
private:
	int TS;
	char Filename[50];
	int N, Prob,mode;
	int EP[4], AP[3], ER[6], AR[6];
	RandGen G;
	EarthArmy E ;
	AlienArmy A;
	LinkedQueue<unit*> KilledList;
	LinkedQueue<unit*> TempList;
	int Kcount;
	int Shots[6];   //first 3 pos are shots fired by EarthForces
public:             //to be deleted
	Game();
	void LoadParameters(char FileName[]);
	bool EnqueueKilled(unit*& d);
	EarthArmy& GetEArmy();
	AlienArmy& GetAArmy();
	int GetTS();
	void PrintKList();
	void GenerateWarReport();
	void TestCode();
	void Interface();
	~Game();
};

