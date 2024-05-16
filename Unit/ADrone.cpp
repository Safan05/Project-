#include "ADrone.h"
#include"ETank.h"

ADrone::ADrone(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool ADrone::attack(Game* const & GPtr)
{
	bool flag = false;
	int j;
	LinkedListStack<unit*> Ttemp;
	priQueue<unit*> Gtemp;
	unit* enemy = NULL;
	int ac = GetAC();
	//if Earth gunnery exist,attack earth tanks with only half the attack capacity
	if (GPtr->GetEArmy().GetEG().GetGcount() > 0)
		ac = GetAC() / 2;
	for (int i = 0; i < ac; i++)
	{
		if (GPtr->GetEArmy().GetET().pop(enemy))
		{
			flag = true;
			//calculate the damage and decrement enemy's health
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			//add enemy's ID to the attacked list
			GetattackedIDs().enqueue(enemy->GetId());
			//set the output file parameters
			if (!enemy->Wasattacked())
			{
				GPtr->GetEArmy().IncAttackCount();

				enemy->SetAttacked(true);
				enemy->SetTa(GPtr->GetTS());
				GPtr->SetEDf(GPtr->GetTS() - enemy->GetJoin());
			}
			//if enemy's health reaches 0, add it to killed list 
			if (enemy->is_killed())
			{
				enemy->SetTd(GPtr->GetTS());
				GPtr->AddKilled(enemy);
			}
			//if enemy is still alive, add it to uml or temp list according to its health percentage 
			else
			{
				int h = enemy->GetHPercent();
				if (h <= 20)
				{
					ETank* et = dynamic_cast<ETank*> (enemy);
					et->setUmlJoinTime(GPtr->GetTS());
					GPtr->GetEArmy().GetUL().AddUnit(enemy);
				}
				else Ttemp.push(enemy);
			}
		}
	}
	//return all units in temp list to their original list
	while (Ttemp.pop(enemy))
		GPtr->GetEArmy().GetET().push(enemy);
	enemy = NULL;
	//////////////////////////////////////////////////////////////////////////////////////
	//Attacking Gunnery with half attack capacity
	for (int i = ac; i < GetAC(); i++)
	{
		if (GPtr->GetEArmy().GetEG().dequeue(enemy))
		{
			flag = true;
			//calculate the damage and decrement enemy's health
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			//add enemy's ID to the attacked list
			GetattackedIDs().enqueue(enemy->GetId());
			//set the output file parameters
			if (!enemy->Wasattacked())
			{
				GPtr->GetEArmy().IncAttackCount();
				enemy->SetAttacked(true);
				enemy->SetTa(GPtr->GetTS());
				GPtr->SetEDf(GPtr->GetTS() - enemy->GetJoin());
			}
			//if enemy's health reaches 0, add it to killed list 
			if (enemy->is_killed())
			{
				enemy->SetTd(GPtr->GetTS());
				GPtr->AddKilled(enemy);
			}
			//if enemy is still alive, add it to temp list
			else Gtemp.enqueue(enemy, enemy->GetPow() + enemy->GetHealth());
		}
	}
	//return all units in temp list to their original list
	while (Gtemp.dequeue(enemy, j))
		GPtr->GetEArmy().GetEG().enqueue(enemy);

	return flag;
}

void ADrone::PrintAttacked()
{
	int i;
	if (GetattackedIDs().peek(i))
	{
		cout << "AD " << GetId() << " shots [";
		while (GetattackedIDs().dequeue(i))
		{
			cout << i;
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Earth units shot by AD" << GetId() << endl;
	}
}
