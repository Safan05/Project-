#include "EarthSoldiers.h"
#include<cmath>
#include"..\Game\Game.h"
EarthSoldiers::EarthSoldiers(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
	Scount = 0;
}

bool EarthSoldiers::Enqueue(unit* s)
{
	Scount++;
	return LinkedQueue<unit*>::enqueue(s);
}

bool EarthSoldiers::Dequeue(unit*& s)
{
	Scount--;
	return LinkedQueue<unit*>::dequeue(s);
}

int EarthSoldiers::GetScount()
{
	return Scount;
}

bool EarthSoldiers::attack(Game* GPtr)
{
	LinkedQueue<unit*>templist;
	unit* enemy = nullptr;
	for (int i = 0; i < unit::GetAC(); i++)
	{
		if (GPtr->GetAArmy().getAS().dequeue(enemy))
		{
			double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			if (!enemy->Wasattacked())
			{
				enemy->SetAttacked(true);
				enemy->SetTa(GPtr->GetTS());
			}
			if (enemy->GetHealth() < 0)
			{
				GPtr->EnqueueKilled(enemy);
			}
			else {
				templist.enqueue(enemy);
			}
		}
	}
	while (GPtr->GetAArmy().getAS().dequeue(enemy))
		templist.enqueue(enemy);
	while (templist.dequeue(enemy))
		GPtr->GetAArmy().getAS().enqueue(enemy);
	return true;
}

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


