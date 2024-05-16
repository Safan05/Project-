#include "ASoldier.h"
#include"ESoldier.h"

ASoldier::ASoldier(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool ASoldier::attack(Game* const & GPtr)
{
	bool flag = false;
	unit* enemy = NULL;
	LinkedQueue<unit*> temp, SUtemp;
	int ac = GetAC();
	//if saver units exist,attack earth soldiers with only half the attack capacity
	if (GPtr->GetSArmy().getSU().Getcount() > 0)    
		ac = GetAC() / 2;
	for (int i = 0; i < ac; i++)
	{
		//attack the infected front pointer first if it exsits
		if (GPtr->GetEArmy().GetES().GetInfected())   
		{
			enemy = GPtr->GetEArmy().GetES().GetInfected();
			GPtr->GetEArmy().GetES().GetInfected() = NULL;
		}
		else
			GPtr->GetEArmy().GetES().dequeue(enemy);
		if(enemy)
		{
			flag = true;
			ESoldier* es = dynamic_cast<ESoldier*>(enemy);
			//calculate the damage and decrement enemy's health
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			//add enemy's ID to the attacked list
			if (es->IsInfected())
				GetattackedIDs().enqueue(enemy->GetId() + 10000);  //to know if the id is infected
			else GetattackedIDs().enqueue(enemy->GetId());
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
					es->setUmlJoinTime(GPtr->GetTS());
					GPtr->GetEArmy().GetUL().AddUnit(enemy);
				}
				else temp.enqueue(enemy);
			}
		}
		enemy = NULL;
	}
	//return all units in temp list to their original list
	while (temp.dequeue(enemy))
		GPtr->GetEArmy().GetES().enqueue(enemy);
	enemy = NULL;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if saver units exist,attack saver units with half the attack capacity
	for (int i = ac; i < GetAC(); i++)
	{
		GPtr->GetSArmy().getSU().dequeue(enemy);
		if (enemy)
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
			else SUtemp.enqueue(enemy);
		}
		enemy = NULL;
	}
	//return all units in temp list to their original list
	while (SUtemp.dequeue(enemy))
		GPtr->GetSArmy().getSU().enqueue(enemy);
	return flag;
}

void ASoldier::PrintAttacked()
{
	int i;
	if (GetattackedIDs().peek(i))
	{
		cout << "AS " << GetId() << " shots [";
		while (GetattackedIDs().dequeue(i))
		{
			if (i < 10000)  //soldier is NOT infected
				cout << i;
			else            //soldier is infected
				cout << "\033[32m" << i - 10000 << "\033[0m";
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Earth and saver units shot by AS" << GetId() << endl;
	}
}