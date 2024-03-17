#include "RandGen.h"
#include <iostream>
RandGen::RandGen(int n, int p, int Ep[], int Ap[],int ER[],int AR[],int TS,EarthArmy* E,AlienArmy* AL)
{
	A = 1 + (rand() % 100);
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
	A = 1 + (rand() % 100);
	if (A < p)
		for (int i = 0; i < n; i++) {
			unit* U = GenAliens(Ap,AR);
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
unit* RandGen::GenEarth(int Ep[], int ER[]) {   //instantiate an object of one of Earmy unit
	B = 1 + (rand() % 100);                     //and make unit* point to it
	P = ER[0] + (rand() % (ER[1] - ER[0]+1));
	H = ER[2] + (rand() % (ER[3] - ER[2]+1));
	AC = ER[4] + (rand() % (ER[5] - ER[4]+1));
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
	B = 1 + (rand() % 100);
	P = AR[0] + (rand() % (AR[1] - AR[0]+1));
	H = AR[2] + (rand() % (AR[3] - AR[2]+1));
	AC = AR[4] + (rand() % (AR[5] - AR[4]+1));
	if (B <= Ap[0]) {
		T = aliensoldier;
		unit* U = new AlienSoldiers(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else if (B <= Ap[0] + Ap[1]) {
		T = monster;
		unit* U = new AlienMonsters(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}
	else {
		T = drone;
		unit* U = new AlienDrones(H, P, AC, T);      //switch on type to make appropriate object
		return U;
	}

}
