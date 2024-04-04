#pragma once
#include "..\unit.h"
#include "..\Type.h"
#include "..\EarthForces\EarthArmy.h"
#include "..\Alien Forces\AlienArmy.h"
class soldier;
class ETank;
class EGunnery;
class RandGen
{
private:
	//	int N, Prob, ES, ET, EG, AS, AM, AD;
	double A, B;
	double P, H, AC, T;
public:
	RandGen(int n, int p, int Ep[], int Ap[], int ER[], int AR[], int TS, EarthArmy* E, AlienArmy* Al);
	unit* GenEarth(int Ep[], int ER[]);
	unit* GenAliens(int Ap[], int AR[]);
	double drand(double M, double N);
};

