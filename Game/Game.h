#pragma once
#include "RandGen.h"
#include"..\EarthForces\EarthArmy.h"
#include "..\EarthForces\EarthSoldiers.h"
#include"..\Alien Forces\AlienArmy.h"
class Game
{
private:
	int TS;
	char Filename[50];
	int N, Prob;
	int EP[3], AP[3], ER[6], AR[6];
	RandGen* G;
	EarthArmy E;
	AlienArmy A;
	LinkedQueue<unit*> KilledList;
	int Kcount;
	int Shots[6];   //first 3 pos are shots fired by EarthForces
public:             //to be incremented when game class implements war logic
	Game();
	void LoadParameters(char FileName[]);
	bool EnqueueKilled(unit* d);
	EarthArmy GetEArmy();
	AlienArmy GetAArmy();
	int GetTS();
	void PrintKList();
	void GenerateWarReport();
	void TestCode();
};

