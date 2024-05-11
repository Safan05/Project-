#pragma once
#include "RandGen.h"
#include"..\EarthForces\EarthArmy.h"
#include"..\Alien Forces\AlienArmy.h"
#include"..\Game\KilledList.h"
#include<string>
class Game
{
private:
	int TS;
	char Filename[50];
	int N, Prob,mode;
	int EP[4], AP[3], ER[6], AR[6];
	int infection_prob;
	int SU_Threshold;
	RandGen G;
	EarthArmy E;
	AlienArmy A;
	KilledList K;
	LinkedQueue<unit*> TempList;
	int Kcount;
	int AvgDs[6]; //[0]Df, [1]Dd, [2]Db First three are for Earth,last three for alien    
public:          //implementation in units folder is for Df,where as    
	Game();      //the one inside Func.Enqueue Killed is for Dd and Db
	void LoadParameters(char FileName[]);
	EarthArmy& GetEArmy();
	AlienArmy& GetAArmy();
	KilledList& GetKList();
	void Battle();
	int GetTS();
	bool AddKilled(unit*&);
	void GenerateWarReport();
	string& BattleResult();
	void PrintAverageResults(ofstream& WR, bool IsE, int aliveE, double KilledE, int AliveA, double KilledA);
	void SetEDf(int f);
	void SetADf(int f);
	void SetEDb(int d);
	void SetADb(int d);
	void Interface();
	~Game();
};

