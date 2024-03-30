#include "EarthTank.h"
#include"../Game/Game.h"
EarthTank::EarthTank(double H, int P, int AC, int T) : unit(H, P, AC, T)
{
	ETshots = 0;
	Tcount = 0;
	ESbelow80 = false;
}

bool EarthTank::push(unit*& t)
{
	Tcount++;
	return LinkedListStack<unit*>::push(t);
}

bool EarthTank::pop(unit*& t)
{
	bool check = LinkedListStack<unit*>::pop(t);
	if(check)
	Tcount--;
	return check;
}

bool EarthTank::attack(Game* Gptr)
{
	LinkedListStack<unit*> templist;           //any DS for templist of monsters is valid  
	unit* enemy = nullptr;                     //however stack is easier in pushing
	unit* Eunit = head->getItem();
	if (!Eunit)
	{
		for (int i = 0; i < unit::GetAC() / 2; i++)
		{
			if (Gptr->GetAArmy().getAM().removeAlienMonster(enemy))
			{
				double damage = (Eunit->GetPow() * Eunit->GetHealth() / 100) / sqrt(enemy->GetHealth());
				enemy->DecHealth(damage);
				ETshots++;
				if (!enemy->Wasattacked())
				{
					enemy->SetAttacked(true);
					enemy->SetTa(Gptr->GetTS());
				}
				if (enemy->GetHealth() < 0)
					Gptr->EnqueueKilled(enemy);
				else
					templist.push(enemy);
			}
			else return false;
			while (templist.pop(enemy))
				Gptr->GetAArmy().AddAM(enemy);
		}
		bool AttackAS = ((Gptr->GetEArmy().GetES().GetScount()) < (Gptr->GetAArmy().getAS().getCount() * 30 / 100)) ? true : false;
		if (AttackAS)
			ESbelow80 = true;
		if(!((Gptr->GetEArmy().GetES().GetScount()) >= (Gptr->GetAArmy().getAS().getCount() * 80 / 100)))
		if (ESbelow80)
		{
			LinkedQueue<unit*> templist;
			for (int i = unit::GetAC() / 2; i < unit::GetAC(); i++)
			{
				if (Gptr->GetAArmy().getAS().dequeue(enemy))
				{
					double damage = (Eunit->GetPow() * Eunit->GetHealth() / 100) / sqrt(enemy->GetHealth());
					enemy->DecHealth(damage);
					ETshots++;
					if (!enemy->Wasattacked())
					{
						enemy->SetAttacked(true);
						enemy->SetTa(Gptr->GetTS());
					}
					if (enemy->GetHealth() < 0)
						Gptr->EnqueueKilled(enemy);
					else
						templist.enqueue(enemy);
				}
				else return false;
				while (templist.dequeue(enemy))
					Gptr->GetAArmy().getAS().enqueue(enemy);
			}
		}
		return true;
	}
	else
		return false;
}

int EarthTank::GetTcount()
{
	return Tcount;
}

void EarthTank::PrintET()
{
	Node<unit*>* temp = head;
	while (temp)
	{
		temp->getItem()->PrintUnit();
		if (temp->getNext())       //Printing style fix
			cout << ", ";
		temp = temp->getNext();
	}
}
