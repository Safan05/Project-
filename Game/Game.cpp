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
	char x = 'a';
	while (x != 'x') {
		TS++;
		cout << "Current TimeStep : " <<TS<<endl;
		cout << "===========================" << endl;
		cout << "Enter any char to generate army : ";
		cin >> x;
		cout << endl;
		E.PrintArmy();
		cout << endl << "===========================" << endl;
		G = new RandGen(N, Prob, EP, AP, ER, AR,&E);
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
