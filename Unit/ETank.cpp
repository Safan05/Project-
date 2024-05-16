#include "ETank.h"

ETank::ETank(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
    ESbelow80 = false;
}

bool ETank::attack(Game* const & Gptr)
{

	LinkedListStack<unit*> templist;           //any DS for templist of monsters is valid  
	unit* enemy = nullptr;                     //however stack is easier in pushing
	int ac = unit::GetAC();
	if (Gptr->GetAArmy().getAS().getCount() > 0)
		ac = unit::GetAC() / 2;
	for (int i = 0; i < ac; i++)
	{
		if (Gptr->GetAArmy().getAM().removeAlienMonster(enemy))
		{
			double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			GetattackedIDs().enqueue(enemy->GetId());
			if (!enemy->Wasattacked())
			{
				Gptr->GetAArmy().IncAttackCount();
				enemy->SetAttacked(true);
				enemy->SetTa(Gptr->GetTS());
				Gptr->SetADf(Gptr->GetTS() - enemy->GetJoin());
			}
			if (enemy->is_killed())
			{
				enemy->SetTd(Gptr->GetTS());
				Gptr->AddKilled(enemy);
			}
			else
				templist.push(enemy);
		}
	}
	while (templist.pop(enemy))
		Gptr->GetAArmy().getAM().AddAlienMonster(enemy);
	bool AttackAS = ((Gptr->GetEArmy().GetES().GetScount()) < (Gptr->GetAArmy().getAS().getCount() * 30.0 / 100)) ? true : false;
	if (AttackAS)
		ESbelow80 = true;  //to continue attacking till > 80%
	if (!((Gptr->GetEArmy().GetES().GetScount()) >= (Gptr->GetAArmy().getAS().getCount() * 80.0 / 100)))
		if (ESbelow80)
		{
			LinkedQueue<unit*> templist;
			for (int i = ac; i < unit::GetAC(); i++)
			{
				if (Gptr->GetAArmy().getAS().dequeue(enemy))
				{
					double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
					enemy->DecHealth(damage);
					GetattackedIDs().enqueue(enemy->GetId());
					if (!enemy->Wasattacked())
					{
						Gptr->GetAArmy().IncAttackCount();
						enemy->SetAttacked(true);
						enemy->SetTa(Gptr->GetTS());
						Gptr->SetADf(Gptr->GetTS() - enemy->GetJoin());
					}
					if (enemy->is_killed())
					{
						enemy->SetTd(Gptr->GetTS());
						Gptr->AddKilled(enemy);
					}
					else
						templist.enqueue(enemy);
				}
			}
			while (templist.dequeue(enemy))
				Gptr->GetAArmy().getAS().enqueue(enemy);
		}
		else ESbelow80 = false;  //reached 80% or more
	return true;
}

void ETank::PrintAttacked()
{
	if (!GetattackedIDs().isEmpty())
	{
		int id;
		cout<<"ET "<<GetId() << " shots [";
		while (GetattackedIDs().dequeue(id))
		{
			cout << id;
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Alien units shot by ET" << GetId() << endl;
	}
}
void ETank::setUmlJoinTime(int t)
{
	UmlJoinTime = t;
}

int ETank::getUmlJoinTime()
{
	return UmlJoinTime;
}

