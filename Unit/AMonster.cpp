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
	LinkedQueue<unit*> Stemp;
	unit* enemy = NULL;

	//Attacking tanks with half attack capacity
	for (int i = 0; i < GetAC() / 2; i++)
	{
		if (GPtr->GetEArmy().GetET().pop(enemy))
		{
			flag = true;
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
			if (damage / enemy->GetHealth() >= 0.08 && damage < enemy->GetHealth())
			{
				ETank* et = dynamic_cast<ETank*> (enemy);
				et->setUmlJoinTime(GPtr->GetTS());
				GPtr->GetEArmy().GetUL().AddUnit(enemy);
			}
			enemy->DecHealth(damage);
			GetattackedIDs().enqueue(enemy->GetId());
			if (!enemy->Wasattacked())
			{
				GPtr->GetEArmy().IncAttackCount();
				enemy->SetAttacked(true);
				enemy->SetTa(GPtr->GetTS());
				GPtr->SetEDf(GPtr->GetTS() - enemy->GetJoin());

			}
			if (enemy->is_killed())
			{
				enemy->SetTd(GPtr->GetTS());
				GPtr->AddKilled(enemy);
			}
			else Ttemp.push(enemy);
		}
	}
	while (Ttemp.pop(enemy))
		GPtr->GetEArmy().GetET().push(enemy);

	//Attacking soldiers with half attack capacity
	for (int i = GetAC() / 2; i < GetAC(); i++)
	{
		if (GPtr->GetEArmy().GetES().dequeue(enemy))
		{
			flag = true;
			int InfProp = (rand() % 100) + 1;   //checks whether the enemy sould be attacked or infected
			if (InfProp > 2)        //2% probability to infect the soldier
			{
				double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
				if (damage / enemy->GetHealth() >= 0.08 && damage < enemy->GetHealth())
				{
					ESoldier* es = dynamic_cast<ESoldier*> (enemy);
					es->setUmlJoinTime(GPtr->GetTS());
					GPtr->GetEArmy().GetUL().AddUnit(enemy);
				}
				if (!enemy->Wasattacked())
				{
					GPtr->GetEArmy().IncAttackCount();
					enemy->SetAttacked(true);
					enemy->SetTa(GPtr->GetTS());
					GPtr->SetEDf(GPtr->GetTS() - enemy->GetJoin());
				}
				if (enemy->is_killed())
				{
					enemy->SetTd(GPtr->GetTS());
					GPtr->AddKilled(enemy);
				}
				else Stemp.enqueue(enemy);
		
			}
			else
			{

				ESoldier* toInfect = dynamic_cast<ESoldier*>(enemy);
				if (!toInfect->isImmune())   //cannot reinfect an immune soldier
				{
					toInfect->SetInfected(true);
					//toInfect->SpreadInfection(GPtr);
				}
			}
		}
	}
	while (Stemp.dequeue(enemy))
		GPtr->GetEArmy().GetES().enqueue(enemy);

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
			cout << i;
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Earth units shot by AM" << GetId() << endl;
	}
}