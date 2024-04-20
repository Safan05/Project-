#include "EarthArmy.h"
#include<iostream>
using namespace std;

EarthArmy::EarthArmy(Game* g) //should be deleted??
{
	Gptr = g;
	id = 0;
}

bool EarthArmy::AddUnit(unit*& u)
{
	u->SetId(id++);
	switch (u->GetType())
	{
	case earthsoldier:
		ES.enqueue(u);
		break;
	case tank:
		ET.push(u);
		break;
	case gunnery:
		EG.enqueue(u);
		break;
	default:
		break;
	}
	return true;
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