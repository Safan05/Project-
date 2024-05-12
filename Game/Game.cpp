#include "Game.h"
#include <fstream>
#include"../Unit/HUnit.h"
#include <Windows.h>
#include <iostream>
using namespace std;
Game::Game()
{
	TS = 0;
	this->Interface(); // just a function for printing and taking values at the beginning of the program
	LoadParameters(Filename);
	for (int i = 0; i < 3; i++) AvgDs[i] = 0;
	cout << "\n";
	if (mode == '1')
	{
		char x;
		cout << "Enter any key to start : ";
		cin >> x;
		cout << endl;
		while (x != 'x') {
			TS++;

			this->Call_Generator();
			this->InteractiveMode();

			cin >> x;
			cout << endl;
			if (TS >= 50) 
			{
				this->GenerateWarReport();
					cout << "\033[1;31mYou have reached the limit of generating more units!\033[0m";
					break;
			}					
		}
	}
	else
		if (mode == '2')
		{
			char L[34] = "Loading Your file is in progress";
			for (int i = 0; i < 34; i++) {
				cout << L[i];
				Sleep(20);
			}
			cout << "\n";
			for (int i = 0; i < 34; i++) {
				cout << "\033[32m" << char(219) << "\033[0m";
				Sleep(20);
			}
			while (TS < 50) {
				TS++;
				this->Call_Generator();
				this->Battle();
			}
			this->GenerateWarReport();
		}
}

	
	void Game::LoadParameters(char FileName[])
	{
		ifstream In;
		char path[80] = "Input/";
		strncat_s(path, FileName,80);
		In.open(path, ios::in);
		if (In.is_open()) {
			In >> N;
			int sum = 0;
			for (int i = 0; i < 4; i++) {
				In >> EP[i];
				if (EP[i] < 0)	//validation that the probability is not negative
					EP[i] = 0;
				sum += EP[i];
			}
			if (sum != 100) {	//Validation that the sum of probabilities to generate earth army units of them doesn't exceed 100
				EP[0] = 30;
				EP[1] = 30;
				EP[2] = 40;
			}
			sum = 0;
			for (int i = 0; i < 3; i++) {
				In >> AP[i];
				if (AP[i] < 0)	//validation that the probability is not negative
					AP[i] = 0;
				sum += AP[i];
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
					ER[i] *= -1;
			}
			for (int i = 0; i < 6; i++) {
				In >> AR[i];
				if (AR[i] < 0)
					AR[i] *= -1;
			}
			In >> infection_prob;
			In >> SU_Threshold;
			for (int i = 0; i < 6; i++) {
				In >> SR[i];
				if (SR[i] < 0)
					SR[i] *= -1;
			}
		}
		else {
			cout << "\033[1;31mNo valid file exists with this name enter the right name: \033[0m" << "\n";
			cin >> Filename;
			LoadParameters(Filename);
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
	while (mode != '1' && mode != '2') {
		char Q[100] = "\033[1;31mThis is not a valid mode please enter 1 for interactive mode and 2 for silent mode\033[0m \n";
		for (int i = 0; i < 100; i++) {
			cout << Q[i];
			Sleep(20);
		}
		cin >> mode;
	}
	char M[29] = "Enter The file name to load";
	for (int i = 0; i < 29; i++) {
		cout << M[i];
		Sleep(20);
	}
	cout << "\n";
	std::cin >> Filename;
}

EarthArmy& Game::GetEArmy()
{
	return E;
}

AlienArmy& Game::GetAArmy()
{
	return A;
}

KilledList& Game::GetKList()
{
	return K;
}

void Game::Battle()
{
	E.EarthAttack(this);
	A.Alienattack(this);
	S.SUattack(this);
}

int Game::GetTS()
{
	return TS;
}
bool Game::AddKilled(unit*& d)
{
	HUnit* h = dynamic_cast<HUnit*>(d);
	d->SetTd(this->GetTS());
	int id = d->GetId();
	if (id <= 999 && id >= 1) {
		AvgDs[0] += d->GetTa() - d->GetJoin();
		if(!h)       //Heal units heal already attacked units therefore their Ta,Df are already set
			AvgDs[1] += TS - d->GetTa();
		AvgDs[2] += TS - d->GetJoin();
	}
	else {
		AvgDs[3] += d->GetTa() - d->GetJoin();
		AvgDs[4] += TS - d->GetTa();
		AvgDs[5] += TS - d->GetJoin();
	}
	return K.AddKilled(d);
}

void Game::GenerateWarReport()
{
	ofstream WR("War Report.txt", ios::out);
	WR << "\t\t\t\t\t\tEarth VS Aliens War Report\n\n";
	WR << "Td\t\t\tID   \t\t\t\tTj\t\t\t\tDf\t\t\t\tDd\t\t\t\tDb\n";
	K.PrintReports(WR);
	WR << "\nBattle Result : "; 
	if (TS > 40)
	{
		WR << BattleResult();

	}
	//===============================Earth Forces Stats=====================================

	WR << "\n\t\t\tEarth Forces\n ";
	WR << "ES count : " << E.GetES().GetScount() << "\t\tET count : "
		<< E.GetET().GetTcount() << "\t\tEG count : " << E.GetEG().GetGcount() << endl;
	WR << "\tES_Destructed/ ES_Total = ";
	double TotalES = E.GetES().GetScount() + *(K.GetEcount());
	double TotalET = E.GetET().GetTcount() + *(K.GetEcount() + 1);
	double TotalEG = E.GetEG().GetGcount() + *(K.GetEcount() + 2);
	double TotalInfected_Healed = E.GetES().GetInfCount() + K.GetInf_HealCount();
	if (TotalES)
		WR << (*K.GetEcount() / TotalES) * 100 << "%" << endl;                    else WR << "0\n";
	WR << "\tET_Destructed/ ET_Total = ";
	if (TotalET) 
		WR << (*(K.GetEcount() + 1) / TotalET) * 100 << "%" << endl;              else WR << "0\n";
	WR << "\tEG_Destructed/ EG_Total = ";
	if (TotalEG)
		WR << (*(K.GetEcount() + 2) / TotalEG) * 100 << "%" << endl;               else WR << "0\n";
	double TotalEU = E.GetEG().GetGcount() + E.GetES().GetScount() + E.GetET().GetTcount();
	WR << "\tES_Infected_Healed/ ES_Total = ";
	if (TotalInfected_Healed)
		WR << (E.GetES().GetInfCount() / TotalInfected_Healed) * 100 << "%" << endl;
	                                                                else WR << "0\n";
	WR << "\nTotal_Destructed/ Total units = ";
	if (TotalEU)
		WR << ((K.Ecount()) / (TotalEU + K.Ecount())) * 100 << "%" << endl;    	else WR << "0";
	PrintAverageResults(WR, 1, TotalEU, K.Ecount(), 0, 0);


	//===============================Alien Forces Stats=====================================

	WR << "\n\t\t\tAlien Forces\n ";
	WR << "AS count : " << A.getAS().getCount() << "\t\tAD count : "
		<< A.getAD().getCount() << "\t\tAM count : " << A.getAM().getCount() << endl;
	double TotalAS = A.getAS().getCount() + *(K.GetAcount());
	double TotalAD = A.getAD().getCount() + *(K.GetAcount() + 1);
	double TotalAM = A.getAM().getCount() + *(K.GetAcount() + 2);
	WR << "\tAS_Destructed/ AS_Total = ";
	if (TotalAS)
		WR << (*(K.GetAcount()) / TotalAS) * 100 << "%" << endl;               else WR << "0\n";
	WR << "\tAD_Destructed/ AD_Total = ";
	if (TotalAD) 
		WR << (*(K.GetAcount() + 1) / TotalAD) * 100 << "%" << endl;           else WR << "0\n";
	WR << "\tAM_Destructed/ AM_Total = ";
	if (TotalAM)
		WR << (*(K.GetAcount() + 2) / TotalAM) * 100 << "%" << endl;           else WR << "0\n";
	double TotalAU = A.getAS().getCount() + A.getAD().getCount() + A.getAM().getCount();
	WR << "\nTotal_Destructed/ Total units = ";
	if (TotalAU)
		WR << (K.Acount() / (TotalAU + K.Acount())) * 100 << "%" << endl;       else WR << "0";
	PrintAverageResults(WR, 0, 0, 0, TotalAU, K.Acount());
}
const char* Game::BattleResult()
{
	char result[6];
	double TotalEU = E.GetEG().GetGcount() + E.GetES().GetScount() + E.GetET().GetTcount();
	double TotalAU = A.getAS().getCount() + A.getAD().getCount() + A.getAM().getCount();
	bool es, et, eg, as, ad, am;
	es = !E.GetES().isEmpty();
	et = !E.GetET().isEmpty();
	eg = !E.GetEG().isEmpty();
	as = !A.getAS().isEmpty();
	ad = !A.getAD().isEmpty();
	am = !A.getAM().isEmpty();

	if (TotalEU == 0 && TotalAU == 0)
		strcpy_s(result, "Drawn");
	else
		if (!eg && !et && es && !as && !am && ad)
			strcpy_s(result, "Drawn");
		else
			if (eg && am && !es && !et && !as && !ad)
				strcpy_s(result, "Win");
			else
				if (eg && as && !es && !et && !am && !ad)
					strcpy_s(result, "Drawn");
				else
					if (TotalEU > TotalAU)
						strcpy_s(result, "Win");

					else
						strcpy_s(result, "Loss");
	return result;
}
void Game::PrintAverageResults(ofstream& WR, bool IsE, int aliveE, double KilledE, int AliveA, double KilledA)
{
	if (IsE)
	{
		WR << "\n\tAverage Df, Dd, Db respectively = ";
		if (E.GetAttackCount())
			WR << (AvgDs[0] / double(E.GetAttackCount())) << ", ";
		else WR << "0, ";
		if (KilledE)
		{
			WR << (AvgDs[1] / KilledE) << ", ";
			WR << (AvgDs[2] / KilledE) << "\n";
		}
		else WR << "0, 0, 0\n";
	}
	else
	{
		WR << "\n\tAverage Df, Dd, Db respectively = ";
		if (A.GetAttackCount())
			WR << (AvgDs[3] / double(A.GetAttackCount())) << ", ";
		else WR << "0, ";
		if (KilledA)
		{
			WR << (AvgDs[3] / KilledA) << ", ";
			WR << (AvgDs[5] / KilledA) << "\n";
		}
		else WR << "0, 0, 0\n";
	}
}
void Game::SetEDf(int f)
{
	AvgDs[0] += f;
}
void Game::SetADf(int f)
{
	AvgDs[3] += f;
}
void Game::SetEDb(int d)
{
	AvgDs[2] += d;
}
void Game::SetADb(int d)
{
	AvgDs[5] += d;
}
int Game::getInfectionProb()
{
	return infection_prob;
}
void Game::Call_Generator() // function to call the random generator
{
	if (G.Probability(Prob)) {
		for (int i = 0; i < N; i++) {
			unit* U = G.GenEarth(EP, ER);
			U->SetJoin(TS);
			if (!E.AddUnit(U))
				cout << "No more available IDs";
		}
	}
	if (G.Probability(Prob)) {
		for (int i = 0; i < N; i++) {
			unit* U = G.GenAliens(AP, AR);
			U->SetJoin(TS);
			if (!A.AddUnit(U))
				cout << "No more available IDs";
		}
	}
	if (E.GetES().GetScount() > 0){
		if (E.GetES().GetInfCount() / E.GetES().GetScount() >= SU_Threshold) {
			for (int i = 0; i < N; i++) {
				unit* U = G.GenAllies(SR);
				U->SetJoin(TS);
				if (!S.AddUnit(U))
					cout << "No more available IDs";
			}
		}
		else
			S.destroyArmy();
		}
	E.GetUL().RemoveOlderunits(this);
}
void Game::InteractiveMode() // Calling Battle and printing in the interactive mode
{
	cout << "Current TimeStep : " << TS << endl;
	Battle();
	cout << "============= Earth Forces Alive Units =============" << endl;
	E.PrintArmy();
	cout << "\n============= Alien Forces Alive Units =============" << endl;
	A.PrintArmy();
	if (E.GetES().GetScount() > 0) 
		if (E.GetES().GetInfCount() / E.GetES().GetScount() >= SU_Threshold) {
			cout << "\n============= Allied Forces Alive Units =============" << endl;
			S.PrintArmy();
		}
	cout << "\n============= Units fighting at current step =======" << endl;
	E.PrintAttack();
	A.PrintAttack();
	S.printAttack();
	cout << "\n============= Killed/Destructed Units =============" << endl;
	K.PrintKillled();
	cout << "\n============= UML Units =============" << endl;
	E.GetUL().PrintUML();
	cout << endl << "Enter any key to move to next time step : ";
}
Game::~Game() { 
	unit* temp = nullptr;
	while (TempList.dequeue(temp)) {
		delete temp;
	}
}