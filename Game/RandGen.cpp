#include "RandGen.h"
#include "..\Unit\ESoldier.h"
#include "..\Unit\ETank.h"
#include "..\Unit\EGunnery.h"
#include"..\Unit\ASoldier.h"
#include"..\Unit\AMonster.h"
#include"..\Unit\ADrone.h"
#include <iostream>
RandGen::RandGen(int n, int p, int Ep[], int Ap[], int ER[], int AR[], int TS, EarthArmy* E, AlienArmy* AL)
{
	A = drand(1, 100);
	if (A < p)
		for (int i = 0; i < n; i++) {
			unit* U = GenEarth(Ep, ER);
			U->SetJoin(TS);
			E->AddUnit(U);
		}
	A = drand(1, 100);
	if (A < p)
		for (int i = 0; i < n; i++) {
			unit* U = GenAliens(Ap, AR);
			U->SetJoin(TS);
			if (U->GetType() == aliensoldier)
				AL->AddAS(U);
			//add soldier using alien army class;
			else if (U->GetType() == drone)
				AL->AddAD(U);
			//add drone using alien army class;
			else
				AL->AddAM(U);
			//add monster using alien army class;
		}

}

double RandGen::drand(double M, double N)
{
	return M + (rand() / (RAND_MAX / (N - M)));
}
unit* RandGen::GenEarth(int Ep[], int ER[]) {   //instantiate an object of one of Earmy unit
	B = drand(1, 100);                            //and make unit* point to it
	P = drand(ER[0], ER[1]);
	H = drand(ER[2], ER[3]);
	AC = drand(ER[4], ER[5]);
	if (B <= Ep[0]) {
		T = soldier;
		unit* U = new ESoldier(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else if (B <= Ep[0] + Ep[1]) {
		T = tank;
		unit* U = new ETank(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else {
		T = gunnery;
		unit* U = new EGunnery(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
}
unit* RandGen::GenAliens(int Ap[], int AR[]) {
	B = drand(1, 100);                     //and make unit* point to it
	P = drand(AR[0], AR[1]);
	H = drand(AR[2], AR[3]);
	AC = drand(AR[4], AR[5]);
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
