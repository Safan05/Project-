#include "RandGen.h"
#include "..\Unit\ESoldier.h"
#include "..\Unit\ETank.h"
#include "..\Unit\EGunnery.h"
#include"..\Unit\ASoldier.h"
#include"..\Unit\AMonster.h"
#include"..\Unit\ADrone.h"
#include"..\Unit\HUnit.h"
#include"..\Unit\SaverU.h"
#include <iostream>
RandGen::RandGen()
{

}

double RandGen::drand(double M, double N)
{
	return M + (rand() / (RAND_MAX / (N - M)));
}
bool RandGen::Probability(double prob)
{
	A = drand(1, 100);
	return (A < prob);
}
unit* RandGen::GenEarth(int Ep[], int ER[]) {   //instantiate an object of one of E-army unit and make unit* point to it
	B = drand(1, 100);                          // generating the type of the unit according to it's probability percentage
	P = drand(ER[0], ER[1]);					// generating the power of the unit
	H = drand(ER[2], ER[3]);					// generating the health of the unit
	AC = drand(ER[4], ER[5]);					// generating the attack capacity if the unit
	if (B <= Ep[0]) {
		T = earthsoldier;
		unit* U = new ESoldier(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else if (B <= Ep[0] + Ep[1]) {
		T = tank;
		unit* U = new ETank(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else if(B<=Ep[0]+Ep[1]+Ep[2]) {
		T = gunnery;
		unit* U = new EGunnery(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else {
		T = HealUnit;
		unit* U = new HUnit(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
}
unit* RandGen::GenAliens(int Ap[], int AR[]) {	//instantiate an object of one of A-army unit and make unit* point to it
	B = drand(1, 100);						    // generating the type of the unit according to it's probability percentage
	P = drand(AR[0], AR[1]);					// generating the power of the unit
	H = drand(AR[2], AR[3]);					// generating the health of the unit
	AC = drand(AR[4], AR[5]);					// generating the attack capacity if the unit
	if (B <= Ap[0]) {
		T = aliensoldier;
		unit* U = new ASoldier(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else if (B <= Ap[0] + Ap[1]) {
		T = monster;
		unit* U = new AMonster(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else {
		T = drone;
		unit* U = new ADrone(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}

}

unit* RandGen::GenAllies(int R[])
{
	P = drand(R[0], R[1]);					// generating the power of the unit
	H = drand(R[2], R[3]);					// generating the health of the unit
	AC = drand(R[4], R[5]);					// generating the attack capacity if the unit}
	T = SaverUnit;
	unit* U = new SaverU(H, P, AC, T);      //switch on type to make appropriate object
	return U;
}