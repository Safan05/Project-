#pragma once
#include "RandGen.h"
#include"..\EarthForces\EarthArmy.h"
#include"..\Alien Forces\AlienArmy.h"
#include"..\Allied Forces\AlliedArmy.h"
#include"..\Game\KilledList.h"
class Game
{
private:
	int TS;
	char Filename[50],mode;
	int N, Prob;
	int EP[4], AP[3], ER[6], AR[6],SR[6];
	int infection_prob;
	int SU_Threshold;
	RandGen G;
	EarthArmy E;
	AlienArmy A;
	AlliedArmy S;
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
	const char* BattleResult();
	void PrintAverageResults(ofstream& WR, bool IsE, int aliveE, double KilledE, int AliveA, double KilledA);
	void SetEDf(int f);
	void SetADf(int f);
	void SetEDb(int d);
	void SetADb(int d);
	int getInfectionProb();
	void Call_Generator();
	void InteractiveMode();
	void Interface();
	~Game();
};

