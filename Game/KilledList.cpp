#include "KilledList.h"
#include"../Unit/ESoldier.h"
#include<iostream>
#include"Game.h"
#include"../Unit/unit.h"
using namespace std;

KilledList::KilledList()
{
	count = 0;
	attackcount = 0;
	healunits = 0;
	infect_healed_Count = 0;
	for (int i = 0; i < 3; i++)
	{
		EForces[i] = 0;
		AForces[i] = 0;
	}
}

bool KilledList::AddKilled(unit*& d)
{
	if (d)
	{
		if (d->GetId() > 0 && d->GetId() <= 999)
		{
			if (d->Wasattacked())
				attackcount++;
		}
		if (d->GetType() == HealUnit)
			healunits++;
		if (LinkedQueue<unit*>::enqueue(d))
		{
			count++;
			switch (d->GetType())
			{
			case earthsoldier:
			{
				EForces[0]++;
				ESoldier* e = dynamic_cast<ESoldier*>(d);
				if (e && (e->IsInfected() || e->isImmune()))
					infect_healed_Count++;
			}
			break;
			case tank: EForces[1]++; break;
			case gunnery: EForces[2]++; break;
			case aliensoldier: AForces[0]++; break;
			case drone: AForces[1]++; break;
			case monster: AForces[2]++; break;
			default:
				break;
			}
			return true;
		}
	}
	return false;
}

void KilledList::PrintKillled()
{
	Node<unit*>* temp = frontPtr;
	cout << count << " units [";
	while (temp)
	{
		temp->getItem()->PrintUnit();
		if (temp->getNext())     //Printing style fix
			cout << ", ";
		temp = temp->getNext();
	}
	cout << "]\n";
}

void KilledList::PrintReports(std::ofstream& f)
{
	Node<unit*>* temp = frontPtr;
	while (temp)
	{
		temp->getItem()->DeathReport(f);
		temp = temp->getNext();
	}
}

int* KilledList::GetEcount()
{
	return EForces;
}

int* KilledList::GetAcount()
{
	return AForces;
}

int KilledList::Ecount()
{
	return EForces[0] + EForces[1] + EForces[2];
}

int KilledList::Acount()
{
	return AForces[0] + AForces[1] + AForces[2];
}

void KilledList::incattackcount()
{
	attackcount++;
}

int KilledList::GetAttCount()
{
	return attackcount;
}

int KilledList::GetHealUcount()
{
	return healunits;
}

int KilledList::GetInf_HealCount()
{
	return infect_healed_Count;
}

KilledList::~KilledList()
{
	unit* temp = nullptr;
	while (dequeue(temp)) {
		delete temp;
	}
}
