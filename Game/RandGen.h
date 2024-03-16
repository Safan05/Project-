#pragma once
#include "..\unit.h"
#include "..\Type.h"
#include "..\EarthForces\EarthArmy.h"
#include "..\EarthForces\EarthArmy.h"
#include "..\EarthForces\EarthArmy.h"
class RandGen
{
private:
//	int N, Prob, ES, ET, EG, AS, AM, AD;
	int A,B;
	int P, H, AC,T;
public:
	RandGen(int n, int p, int Ep[], int Ap[],int ER[], int AR[],int TS,EarthArmy* E);
	unit* GenEarth(int Ep[], int ER[]);
	unit* GenAliens(int Ap[], int AR[]);
};

