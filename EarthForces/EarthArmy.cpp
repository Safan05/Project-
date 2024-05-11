#include "EarthArmy.h"
#include<iostream>
#include"../Game/Game.h"
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
	case HealUnit:
		HU.push(u);
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

UML& EarthArmy::GetUL()
{
	return UL;
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
	///////////////Printing HU List/////////////////

	cout << HU.GetHUcount() << " HU [";
	HU.PrintHU();
	cout << "]";
	cout << endl;
}

void EarthArmy::PrintAttack()
{
	unit* u = nullptr; int g;
	if (ES.peek(u))
		u->PrintAttacked();
	if (ET.peek(u))
		u->PrintAttacked();
	if (EG.peek(u, g))
		u->PrintAttacked();
}


void EarthArmy::EarthAttack(Game* const& Gptr)
{
	unit* u = nullptr;
	if (ES.peek(u))
		u->attack(Gptr);
	if(ET.peek(u))
		u->attack(Gptr);
	int g;
	if(EG.peek(u, g))
		u->attack(Gptr);
	
	// healing logic
	unit* H;
	if (HU.pop(H)) {
		H->attack(Gptr);
		Gptr->EnqueueKilled(H);
	}
}
