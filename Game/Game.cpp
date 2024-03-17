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
	char x ;
	cout << "Enter any key to start : ";
	cin >> x;
	cout << endl;
	while (x != 'x') {
		TS++;
		cout << "Current TimeStep : " <<TS<<endl;
		cout << "============= Earth Forces Alive Units =============" << endl;
		E.PrintArmy();
		cout << "============= Alien Forces Alive Units =============" << endl<<endl<<endl<<endl;//empty lines for now
		cout << "============= Killed/Destructed Units =============" << endl<<endl<<endl;
		G = new RandGen(N, Prob, EP, AP, ER, AR,TS,&E);
		cout << "Enter any key to move to next time step : ";
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

bool Game::EnqueueKilled(unit* d)
{
	d->SetTd(TS);
	Kcount++;
	return KilledList.enqueue(d);
}

EarthArmy Game::GetEArmy()
{
	return EarthArmy(E);
}

AlienArmy Game::GetAArmy()
{
	return AlienArmy(A);
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
	{                              //Note:killedlist is ascend.sorted already 
		kunit->DeathReport(WR);    //as it's queue implemented
		TempK.enqueue(kunit);
	}
	while (TempK.dequeue(kunit))
		KilledList.enqueue(kunit);
	WR << "\nBattle Result : ";
	WR << "ES count : " << *E.GetEcount() << "\tET count : "
		<< E.GetEcount()[1] << "\tEG count : " << E.GetEcount()[2] << endl;
}
