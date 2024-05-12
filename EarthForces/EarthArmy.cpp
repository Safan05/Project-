#include "EarthArmy.h"
#include"../Unit/ESoldier.h"
#include<iostream>
#include"../Game/Game.h"
using namespace std;

EarthArmy::EarthArmy() //should be deleted??
{
	id = 1;
	AttackCount = 0;
}

bool EarthArmy::AddUnit(unit*& u)
{
	if (id <= 999)
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
	return false;
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

void EarthArmy::IncAttackCount()
{
	AttackCount++;
}

int EarthArmy::GetAttackCount()
{
	return AttackCount;
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
	{
		ESoldier* eunit = dynamic_cast<ESoldier*>(u);
		if (eunit)
		{
			if (eunit->IsInfected())
			{
				ES.InfEnqueue(u);
				u->attack(Gptr);
			}
			else {
				u->attack(Gptr);
			}
		}
	}
	if (ET.peek(u))
	{
		u->attack(Gptr);
	}
	int g;
	if (EG.peek(u, g))
	{
		u->attack(Gptr);
	}
	// healing logic
	unit* H;
	if (HU.pop(H)) {
		H->attack(Gptr);
		H->SetTd(Gptr->GetTS());
		Gptr->AddKilled(H);
	}
}
