#include "EarthSoldiers.h"
#include<cmath>
#include"..\Game\Game.h"
EarthSoldiers::EarthSoldiers()
{
	Scount = 0;
}

bool EarthSoldiers::enqueue(unit*& s)
{
	Scount++;
	return LinkedQueue<unit*>::enqueue(s);
}

bool EarthSoldiers::dequeue(unit*& s)
{
	if (LinkedQueue<unit*>::dequeue(s))
	{
		Scount--; return true;
	}
	return false;
}

int EarthSoldiers::GetScount()
{
	return Scount;
}
//
//bool EarthSoldiers::attack(Game* GPtr)
//{
//	LinkedQueue<unit*>templist;
//	unit* enemy = nullptr;
//	unit* Eunit = frontPtr->getItem();
//	for (int i = 0; i < unit::GetAC(); i++)
//	{
//		if (GPtr->GetAArmy().getAS().dequeue(enemy))
//		{
//			double damage = (Eunit->GetPow() * Eunit->GetHealth() / 100) / sqrt(enemy->GetHealth());
//			enemy->DecHealth(damage);
//			ESshots++;
//			if (!enemy->Wasattacked())
//			{
//				enemy->SetAttacked(true);
//				enemy->SetTa(GPtr->GetTS());
//			}
//			if (enemy->GetHealth() < 0)
//				GPtr->EnqueueKilled(enemy);
//			else 
//				templist.enqueue(enemy);
//		}
//	}
//	while (templist.dequeue(enemy))
//		GPtr->GetAArmy().getAS().enqueue(enemy);
//	return true;
//}

void EarthSoldiers::PrintES()
{
	Node<unit*>* temp = frontPtr;
	while (temp)
	{
		temp->getItem()->PrintUnit();
		if (temp->getNext())        //Printing style fix
			cout << ", ";
		temp = temp->getNext();
	}
}

EarthSoldiers::~EarthSoldiers()
{
	unit* temp = nullptr;
	while (this->dequeue(temp))
	{
		delete temp;
	}
}


