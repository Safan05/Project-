#include "RandGen.h"
#include <iostream>
double drand(double M, double N)
{
	return M + (rand() / (RAND_MAX / (N - M)));
}
RandGen::RandGen(int n, int p, int Ep[], int Ap[],int ER[],int AR[],int TS,EarthArmy* E)
{
	A = drand(1,100);
	if(A<p)
		for (int i = 0; i < n; i++) {
			unit* U = GenEarth(Ep,ER);
			U->SetJoin(TS);
			if (U->GetType() == soldier)
				E->EnqueueESoldier(U);
			//add soldier using earth army class;
			else if (U->GetType() == gunnery)
				E->EnqueueEGunnery(U);
			//add gunnery using earth army class;
			else
				E->EnqueueETank(U);
			//add Tank using earth army class;
		}
	//A = drand(1,100);
	//if (A < p)
	//	for (int i = 0; i < n; i++) {
	//		unit* U = GenAliens(Ap,AR);
	// 			U->SetJoin(TS);
	//		if (U->GetType() == aliensoldier);
	//		//add soldier using alien army class;
	//		else if (U->GetType() == drone);
	//		//add drone using alien army class;
	//		else;
	//		//add monster using alien army class;
	//	}
}
unit* RandGen::GenEarth(int Ep[], int ER[]) {   //instantiate an object of one of Earmy unit
	B =drand(1,100);                     //and make unit* point to it
	P =drand(ER[0],ER[1]);
	H = drand(ER[2],ER[3]);
	AC = drand(ER[4], ER[5]);
	if (B <= Ep[0]) {
		T = soldier;
		unit* U = new EarthSoldiers(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else if (B <= Ep[0] + Ep[1]) {
		T = tank;
		unit* U = new EarthTank(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else {
		T = gunnery;
		unit* U = new EarthGunnery(H, P, AC, T);      //switch on type to make appropriate object
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
		unit* U = new EarthSoldiers(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else if (B <= Ap[0] + Ap[1]) {
		T = monster;
		unit* U = new EarthSoldiers(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else {
		T = drone;
		unit* U = new EarthSoldiers(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}

}
