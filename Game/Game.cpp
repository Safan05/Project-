#include "Game.h"
#include <fstream>
#include <Windows.h>
#include <iostream>
using namespace std;
Game::Game()
{
	TS = 0;
	this->Interface(); // just a function for printing and taking values at the beginning of the program
	LoadParameters(Filename);
	if (mode == 1) {
		char x;
		cout << "Enter any key to start : ";
		cin >> x;
		while (x != 'x') {
			TS++;
			//G = new RandGen(N, Prob, EP, AP, ER, AR, TS, &E, &A);
			if (G.Probability(Prob)) {
				for (int i = 0; i < N; i++) {
					unit* U = G.GenEarth(EP, ER);
					U->SetJoin(TS);
					E.AddUnit(U);
				}
			}
			if (G.Probability(Prob)) {
				for (int i = 0; i < N; i++) {
					unit* U = G.GenAliens(AP, AR);
					U->SetJoin(TS);
					A.AddUnit(U);
				}
			}
			//TestCode();
			cout << "Current TimeStep : " << TS << endl;
			cout << "============= Earth Forces Alive Units =============" << endl;
			E.PrintArmy();
			cout << "\n============= Alien Forces Alive Units =============" << endl;
			A.PrintArmy();
			cout << "\n============= Units fighting at current step =======" << endl;
			unit* EU = nullptr, * ET = nullptr;
			E.GetES().peek(EU);
			if (EU) {
				EU->attack(this);
				EU->PrintAttacked();
			}
			E.GetET().peek(ET);
			if (ET) {
				ET->attack(this);
				ET->PrintAttacked();
			}
			A.Alienattack(this);
			cout << "\n============= Killed/Destructed Units =============" << endl;
			this->PrintKList();
			cout << endl << "Enter any key to move to next time step : ";
			cin >> x;
			cout << endl;
			while (x != 'x') {
				TS++;
				if (G.Probability(Prob)) {
					for (int i = 0; i < N; i++) {
						unit* U = G.GenEarth(EP, ER);
						U->SetJoin(TS);
						E.AddUnit(U);
					}
				}
				if (G.Probability(Prob)) {
					for (int i = 0; i < N; i++) {
						unit* U = G.GenAliens(AP, AR);
						U->SetJoin(TS);
						A.AddUnit(U);
					}
				}
				E.attack(this);
				unit* EU = nullptr, * AU = nullptr;
				E.GetES().peek(EU);
				if (EU)
				{
					EU->attack(this);
					EU->PrintAttacked();
				}
				cout << "Current TimeStep : " << TS << endl;
				cout << "============= Earth Forces Alive Units =============" << endl;
				E.PrintArmy();
				cout << "============= Alien Forces Alive Units =============" << endl;
				A.PrintArmy();
				cout << "============= Killed/Destructed Units =============" << endl;
				this->PrintKList();
				cout << endl << "Enter any key to move to next time step : ";
				cin >> x;
				cout << endl;
				if (TS >= 50) {
					cout << "\033[1;31mYou have reached the limit of generating more units!\033[0m";
					break;
				}
			}
			this->GenerateWarReport();
		}
	}
	else if (mode == 2) {
		char L[34] = "Loading Your file is in progress";
		for (int i = 0; i < 34; i++) {
			cout << L[i];
			Sleep(20);
		}
		cout << "\n";
		for (int i = 0; i < 34; i++) {
			cout << "\033[32m"<<char(219)<<"\033[0m";
			Sleep(20);
		}
		while (TS <= 50) {
			TS++;
			if (G.Probability(Prob)) {
				for (int i = 0; i < N; i++) {
					unit* U = G.GenEarth(EP, ER);
					U->SetJoin(TS);
					E.AddUnit(U);
				}
			}
			if (G.Probability(Prob)) {
				for (int i = 0; i < N; i++) {
					unit* U = G.GenAliens(AP, AR);
					U->SetJoin(TS);
					A.AddUnit(U);
				}
			}
			E.attack(this);
			unit* EU = nullptr, * AU = nullptr;
			E.GetES().peek(EU);
			if (EU)
			{
				EU->attack(this);
			}
		}
		this->GenerateWarReport();
	}
}


void Game::LoadParameters(char FileName[])
{
	ifstream In;
	In.open(FileName, ios::in);
	if (In.is_open()) {
		In >> N;
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			In >> EP[i];
			if (EP[i] < 0)	//validation that the probability is not negative
				EP[i] = 0;
			sum += EP[i];
		}
		if (EP[3] > 5) {
			sum -= EP[3] - 5;
			EP[3] = 5;
		}
		if (sum != 100) {	//Validation that the sum of probabilities to generate earth army units of them doesn't exceed 100
			EP[0] = 30;
			EP[1] = 30;
			EP[2] = 35;
			EP[3] = 5;
		}
		sum = 0;
		for (int i = 0; i < 3; i++) {
			In >> AP[i];
			if (EP[i] < 0)	//validation that the probability is not negative
				EP[i] = 0;
			sum += EP[i];
		}
		if (sum != 100) {	//Validation that the sum of probabilities to generate alien army units of them doesn't exceed 100
			AP[0] = 30;
			AP[1] = 30;
			AP[2] = 40;
		}
		In >> Prob;
		if (Prob > 100 || Prob < 0)	// validation that the probability to generate the army isn't negative or exceeds 100
			Prob = 100;
		for (int i = 0; i < 6; i++) {
			In >> ER[i];
			if (ER[i] < 0)
				ER[i] *= -1;		// for the hyphen in the input file and also for validation
		}
		for (int i = 0; i < 6; i++) {
			In >> AR[i];
			if (AR[i] < 0)
				AR[i] *= -1;	   // for the hyphen in the input file and also for validation
		}
	}
	else {
		cout << "\033[1;31mNo valid file exists with this name enter the right name: \033[0m" << "\n";
		cin >> Filename;
		LoadParameters(Filename);
	}
}
void Game::TestCode() {
	double x = G.drand(1, 100);
	if (x < 10)
	{ 	//pick ES and insert again
		unit* u = nullptr;
		if (E.GetES().dequeue(u))
			E.GetES().enqueue(u);
	}
	else if (x < 20) {	//pick ET and insert in Killed list

		unit* u = nullptr;
		if (E.GetET().pop(u))
			EnqueueKilled(u);
	}
	else if (x < 30) {	//pick EG , decrement it's length to half and insert again
		unit* u = nullptr;
		if (E.GetEG().dequeue(u))
		{
			u->DecHealth(u->GetHealth() / 2);
			E.GetEG().enqueue(u);
		}
	}
	else if (x < 40) {	//pick 5 AS from their list,decrement their health, put them in temp list then insert again to original length
		for (int i = 0; i < 5; i++) {
			unit* u = nullptr;
			if (A.getAS().dequeue(u))
			{
				u->DecHealth(u->GetHealth() / (G.drand(2, 10)));
				TempList.enqueue(u);
			}
		}
		for (int i = 0; i < 5; i++) {
			unit* u = nullptr;
			if (TempList.dequeue(u))
				A.getAS().enqueue(u);

		}
	}
	else if (x < 50) { 	//pick 5 monsters from their list and insert them again

		for (int i = 0; i < 5; i++) {
			unit* u = nullptr;
			if (A.getAM().removeAlienMonster(u))
				A.getAM().AddAlienMonster(u);
		}
	}
	else if (x < 60) { 	//pick 6 drones from their list and insert them in killed list

		for (int i = 0; i < 3; i++) {
			unit* u1 = nullptr, * u2 = nullptr;
			if (A.getAD().dequeue(u1, u2)) {
				EnqueueKilled(u1);
				if (u2)
					EnqueueKilled(u2);
			}
		}
	}
}
void Game::Interface()
{
	char H[56] = "\033[1;31mHello, Welcome to Supernova's war simulator\033[0m";
	for (int i = 0; i < 56; i++) {
		cout << H[i];
		Sleep(20);
	}
	cout << "\n";
	char Q[55] = "Enter 1 for interactive mode and 2 for silent mode : ";
	for (int i = 0; i < 55; i++) {
		cout << Q[i];
		Sleep(20);
	}
	cin >> mode;
	while (mode != 1 && mode != 2) {
		char Q[100] = "\033[1;31mThis is not a valid mode please enter 1 for interactive mode and 2 for silent mode\033[0m \n";
		for (int i = 0; i < 100; i++) {
			cout << Q[i];
			Sleep(20);
		}
		cin >> mode;
	}
//	cout << "\n";
	char M[29] = "Enter The file name to load";
	for (int i = 0; i < 29; i++) {
		cout << M[i];
		Sleep(20);
	}
	cout << "\n";
	std::cin >> Filename;
}
bool Game::EnqueueKilled(unit*& d)
{
	d->SetTd(TS);
	Kcount++;
	return KilledList.enqueue(d);
}

EarthArmy& Game::GetEArmy()
{
	return E;
}

AlienArmy& Game::GetAArmy()
{
	return A;
}

int Game::GetTS()
{
	return TS;
}

void Game::PrintKList()
{
	unit* temp;
	LinkedQueue<unit*> Ktemp;
	cout << Kcount << " units [";
	for (int i = 0; i < Kcount; i++)
	{
		KilledList.dequeue(temp);
		temp->PrintUnit();
		if (i != Kcount - 1)
			cout << ", ";
		Ktemp.enqueue(temp);
	}
	cout << "]";
	while (Ktemp.dequeue(temp))
		KilledList.enqueue(temp);

}

void Game::GenerateWarReport()
{
	ofstream WR("War Report.txt", ios::out);
	WR << "\tEarth VS Aliens War Report\n";
	WR << "Td\tID\tTj\tDf\tDd\tDb\n";
	LinkedQueue<unit*> TempK;
	unit* kunit; int es = 0, et =0, eg = 0, as = 0, ad = 0, am = 0;
	while (KilledList.dequeue(kunit))
	{                              //Note:killed-list is ascend.sorted already 
		kunit->DeathReport(WR);    //as it's queue implemented
		switch (kunit->GetType())
		{
		case earthsoldier: es++; break;
		case tank: et++; break;
		case gunnery: eg++; break;
		case aliensoldier: as++; break;
		case drone: ad++; break;
		case monster: am++; break;
		default:
			break;
		}
		TempK.enqueue(kunit);
	}
	while (TempK.dequeue(kunit))
		KilledList.enqueue(kunit);
	WR << "\nBattle Result : \n";
	WR << "ES count : " << E.GetES().GetScount() << "\tET count : "
		<< E.GetET().GetTcount() << "\tEG count : " << E.GetEG().GetGcount() << endl;
	WR << "ES_Destructed/ ES_Total = " << es / E.GetES().GetScount() << "\tET_Destructed/ ET_Total = " << et / E.GetET().GetTcount()
		<< "\tEG_Destructed/ EG_Total = " << eg / E.GetEG().GetGcount();
	int TotalU = E.GetEG().GetGcount() + E.GetES().GetScount() + E.GetET().GetTcount();
	WR << "\nTotal_Destructed/ Total units " << (es + et + eg + as + am + ad) / TotalU;
}
Game::~Game() {
	unit* temp = nullptr;
	while (KilledList.dequeue(temp))
		delete temp;
	temp = nullptr;
	while (TempList.dequeue(temp))
		delete temp;
}