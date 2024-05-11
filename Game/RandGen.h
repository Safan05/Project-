#pragma once
#include "..\Unit\unit.h"
#include "..\Type.h"
class RandGen
{
private:
	double A, P, H, B; // prob,power,health,type probability
	int AC, T; // attack capacity , type
public:
	RandGen();
	unit* GenEarth(int Ep[], int ER[]);
	unit* GenAliens(int Ap[], int AR[]);
	unit* GenAllies(int R[]);
	double drand(double M, double N);
	bool Probability(double A);
};

