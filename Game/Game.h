#pragma once
#include "RandGen.h"
#include"..\EarthForces\EarthArmy.h"
#include "..\EarthForces\EarthSoldiers.h"
class Game
{
private:
	int TS;
	char Filename[50];
	int N, Prob;
	int EP[3], AP[3], ER[6], AR[6];
	RandGen* G;
	EarthArmy E;
public:
	Game();
	void LoadParameters(char FileName[]);
};

