#include "EarthArmy.h"
#include"../Unit/ESoldier.h"
#include<iostream>
#include"../Game/Game.h"
using namespace std;

EarthArmy::EarthArmy() 
{
	id = 1;
	ESattacker = nullptr;
	ETattacker = nullptr;
	EGattacker = nullptr;
}

bool EarthArmy::AddUnit(unit*& u)
{
	if (id <= 999)               //Ensures Ids fit in range 1 < id < 999
	{
		u->SetId(id++);
		switch (u->GetType())
		{
		case earthsoldier:
			ES.enqueue(u);       //if the new unit is Earth soldier ,add it to ES list
			break;
		case tank:
			ET.push(u);         //if the new unit is Earth tank ,add it to ET list
			break;
		case gunnery:
			EG.enqueue(u);      //if the new unit is Earth gunnery ,add it to EG list
			break;
		case HealUnit:
			HU.push(u);         //if the new unit is Heal  ,add it to HU list
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
	if (ESattacker)         //print units attacked by Earth Soldier at current time step            
		ESattacker->PrintAttacked();       
	if (ETattacker)         //print units attacked by Earth Tank at current time step 
		ETattacker->PrintAttacked();
	if (EGattacker)        //print units attacked by Earth Gunnery at current time step 
		EGattacker->PrintAttacked();
}
void EarthArmy::EarthAttack(Game* const& Gptr)
{
	unit* u = nullptr;
	if (ES.peek(u))
	{
		ESoldier* eunit = dynamic_cast<ESoldier*>(u);  //to check infection state
		if (eunit)
		{
			if (eunit->IsInfected())
			{
				ES.dequeue(u);              //infetced ES must be dequeued to attack other ESoldiers
				ES.GetInfected() = u;      //addresss stored in a pointer to call its (print attacked) later
				u->attack(Gptr);           //Infected Earth Soldier Attack    
			}
			else {
				u->attack(Gptr);     //Earth Soldier Attack    
			}
			ESattacker = u;
		}
	}
	else
		ESattacker = nullptr;
	if (ET.peek(u))
	{
		u->attack(Gptr);            //Earth Tank Attack
		ETattacker = u;
	}
	else
		ETattacker = nullptr;
	int g;
	if (EG.peek(u, g))
	{
		u->attack(Gptr);            //Earth Gunnery Attack 
		EGattacker = u;
	}
	else
		EGattacker = nullptr;
	ES.SpreadInfection();          //Spread Infection if exists infected within the list
	// healing logic
	unit* H;
	if(!UL.isEmpty())
	if (HU.pop(H)) {
		H->attack(Gptr);
		H->SetTd(Gptr->GetTS());
		Gptr->AddKilled(H);
	}
}