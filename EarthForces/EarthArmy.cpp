#include "EarthArmy.h"
#include"../Unit/ESoldier.h"
#include<iostream>
#include"../Game/Game.h"
using namespace std;

EarthArmy::EarthArmy() //should be deleted??
{
	id = 1;
	AttackCount = 0;
	ESattacker = nullptr;
	ETattacker = nullptr;
	EGattacker = nullptr;
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
	if (ESattacker)
		ESattacker->PrintAttacked();
	if (ETattacker)
		ETattacker->PrintAttacked();
	if (EGattacker)
		EGattacker->PrintAttacked();
}
void EarthArmy::EarthAttack(Game* const& Gptr)
{
	if (ES.peek(ESattacker))
	{
		ESoldier* eunit = dynamic_cast<ESoldier*>(ESattacker);
		if (eunit)
		{
			if (eunit->IsInfected())
			{
				ES.InfEnqueue(ESattacker);
				ESattacker->attack(Gptr);
			}
			else {
				ESattacker->attack(Gptr);
			}
		}
	}
	else ESattacker = nullptr;
	if (ET.peek(ETattacker))
	{
		ETattacker->attack(Gptr);
	}
	else ETattacker=nullptr;
	int g;
	if (EG.peek(EGattacker, g))
	{
		EGattacker->attack(Gptr);
	}
	else EGattacker = nullptr;
	// healing logic
	unit* H;
	if (HU.pop(H)) {
		H->attack(Gptr);
		H->SetTd(Gptr->GetTS());
		Gptr->AddKilled(H);
	}
}
