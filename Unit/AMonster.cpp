#include "AMonster.h"
#include"ESoldier.h"
#include"ETank.h"

AMonster::AMonster(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool AMonster::attack(Game* const & GPtr)
{
	bool flag = false;
	LinkedListStack<unit*> Ttemp;
	LinkedQueue<unit*> Stemp, SUtemp;
	unit* enemy = NULL;
	int ac1 = GetAC();
	//if Earth soldiers exist, attack earth tanks with only half the attack capacity
	if (GPtr->GetEArmy().GetES().GetScount() > 0)
		ac1 = GetAC() / 2;
	for (int i = 0; i < ac1; i++)
	{
		GPtr->GetEArmy().GetET().pop(enemy);
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
			}
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
		enemy = NULL;
	}
	//return all units in temp list to their original list
	while (Ttemp.pop(enemy))
		GPtr->GetEArmy().GetET().push(enemy);
   enemy = NULL;
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //Attacking Earth soldiers and Saver units with half attack capacity
	int ac2 = GetAC();
	if (GPtr->GetSArmy().getSU().Getcount() > 0)
		ac2 = 3 * ac2 / 4;
	for (int i = ac1; i < ac2; i++)
	{
		if (GPtr->GetEArmy().GetES().GetInfected())
		{
			enemy = GPtr->GetEArmy().GetES().GetInfected();
			GPtr->GetEArmy().GetES().GetInfected() = NULL;
		}
		else
			GPtr->GetEArmy().GetES().dequeue(enemy);
		if (enemy)
		{
			flag = true;
			ESoldier* es = dynamic_cast<ESoldier*>(enemy);

			int InfProp = (rand() % 100) + 1;              //checks whether the enemy should be attacked or infected
			if (InfProp > GPtr->getInfectionProb())        //probability to attack the soldier
			{
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
					enemy->SetAttacked(true);
					enemy->SetTa(GPtr->GetTS());
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
					else Stemp.enqueue(enemy);
				}

			}
			else    // probability to infect the soldier
			{
				if (!es->isImmune())   //cannot reinfect an immune soldier
				{
					es->SetInfected(true);
					infectedList.enqueue(es->GetId());
					Stemp.enqueue(enemy);
				}
			}
		}
		enemy = NULL;
	}
	//return all units in temp list to their original list
	while (Stemp.dequeue(enemy))
		GPtr->GetEArmy().GetES().enqueue(enemy);
	enemy = NULL;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if saver units exist,attack saver units with 1/4 of the attack capacity
	for (int i = ac2; i < GetAC(); i++)
	{
		if(GPtr->GetSArmy().getSU().dequeue(enemy))
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
	}
	//return all units in temp list to their original list
	while (SUtemp.dequeue(enemy))
		GPtr->GetSArmy().getSU().enqueue(enemy);
	return flag;
}

void AMonster::PrintAttacked()
{
	int i = 0;
	if (GetattackedIDs().peek(i))
	{
		cout << "AM " << GetId() << " shots [";
		while (GetattackedIDs().dequeue(i))
		{
			if (i < 10000)   //unit is NOT infected
				cout << i;
			else             //unit is infected
				cout << "\033[32m" << i - 10000 << "\033[0m";
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Earth and saver units shot by AM" << GetId() << endl;
	}
}

void AMonster::PrintInfected()
{
	int i = 0;
	if (infectedList.peek(i))
	{
		cout << "AM " << GetId() << " infects [";
		while (infectedList.dequeue(i))
		{
			cout << "\033[32m" << i << "\033[0m";
			if (!infectedList.isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Earth units infectd by AM" << GetId() << endl;
	}
}
