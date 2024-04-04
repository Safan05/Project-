#include "EarthArmy.h"
#include<iostream>
#include "../Game/Game.cpp"
using namespace std;

EarthArmy::EarthArmy(Game* g) //null ptr for now
{
	Gptr = g;
	id = 0;
}

bool EarthArmy::AddUnit(unit* u, Type t)
{
	switch (t)
	{
	case soldier:
		AddES(u);
		break;
	case tank:
		AddET(u);
		break;
	case gunnery:
		AddEG(u);
		break;
	default:
		break;
	}
	return true;
}

bool EarthArmy::AddES(unit* s)
{
	s->SetId(id++);
	return ES.enqueue(s);
}

bool EarthArmy::AddET(unit* t)
{
	t->SetId(id++);
	return ET.push(t);
}

bool EarthArmy::AddEG(unit* g)
{
	g->SetId(id++);
	return EG.enqueue(g);
}

EarthSoldiers& EarthArmy::GetES()
{
	return ES;
}

EarthGunnery& EarthArmy::GetEG()
{
	return EG;
}

EarthTanks& EarthArmy::GetET()
{
	return ET;
}

void EarthArmy::PrintArmy()
{
	///////////////Printing ES List/////////////////
	cout << ES.GetScount() << " ES [";
	ES.PrintES();
	cout << "]";
	cout << endl;

	///////////////Printing EG List/////////////////

	cout << EG.GetGcount() << " EG [";
	EG.PrintEG();
	cout << "]";
	cout << endl;
	///////////////Printing ET List/////////////////

	cout << ET.GetTcount() << " ET [";
	ET.PrintET();
	cout << "]";
	cout << endl;
}