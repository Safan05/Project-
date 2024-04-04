#include "Game.h"
#include <fstream>
#include <iostream>
using namespace std;
Game::Game()
{

	TS = 0;
	std::cout << "Enter The file name to load" << endl;
	std::cin >> Filename;
	LoadParameters(Filename);
	char x;
	cout << "Enter any key to start : ";
	cin >> x;
	cout << endl;
	while (x != 'x') {
		TS++;
		G = new RandGen(N, Prob, EP, AP, ER, AR, TS, &E, &A);
		TestCode();
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
	}
}

void Game::LoadParameters(char FileName[])
{
	ifstream In;
	In.open(FileName, ios::in);
	In >> N;
	for (int i = 0; i < 3; i++)
		In >> EP[i];
	for (int i = 0; i < 3; i++)
		In >> AP[i];
	In >> Prob;
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
}
void Game::TestCode() {
	double x = G->drand(1, 100);
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
	else if (x < 40) {	//pick 5 AS from their length,decrement their health, put them in temp list then insert again to original length
		for (int i = 0; i < 5; i++) {
			unit* u = nullptr;
			if (A.getAS().dequeue(u))
				TempList.enqueue(u);
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
bool Game::EnqueueKilled(unit* d)
{
	d->SetTd(TS);
	Kcount++;
	return KilledList.enqueue(d);
}

EarthArmy Game::GetEArmy()
{
	return E;
}

AlienArmy Game::GetAArmy()
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
	unit* kunit;
	while (KilledList.dequeue(kunit))
	{                              //Note:killed-list is ascend.sorted already 
		kunit->DeathReport(WR);    //as it's queue implemented
		TempK.enqueue(kunit);
	}
	while (TempK.dequeue(kunit))
		KilledList.enqueue(kunit);
	WR << "\nBattle Result : ";
	WR << "ES count : " << E.GetES().GetScount() << "\tET count : "
		<< E.GetET().GetTcount() << "\tEG count : " << E.GetEG().GetGcount() << endl;
}