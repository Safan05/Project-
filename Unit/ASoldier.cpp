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
	if (GPtr->GetSArmy().getSU().Getcount() > 0)
		ac = ceil(0.75 * ac);
	for (int i = 0; i < ac; i++)
	{
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
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
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
			else 
			{
				int h = enemy->GetHPercent();
				if (h <= 20)
				{
					ESoldier* es = dynamic_cast<ESoldier*> (enemy);
					es->setUmlJoinTime(GPtr->GetTS());
					GPtr->GetEArmy().GetUL().AddUnit(enemy);
				}
				else temp.enqueue(enemy);
			}
		}
		enemy = NULL;
	}
	while (temp.dequeue(enemy))
		GPtr->GetEArmy().GetES().enqueue(enemy);
	//if saver units exist,attack saver units with quarter the attack capacity
	for (int i = ac; i < GetAC(); i++)
	{
		GPtr->GetSArmy().getSU().dequeue(enemy);
		if (enemy)
		{
			flag = true;
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			GetattackedIDs().enqueue(enemy->GetId());
			if (!enemy->Wasattacked())
			{
				GPtr->GetSArmy().IncAttackCount();
				enemy->SetAttacked(true);
				enemy->SetTa(GPtr->GetTS());
				GPtr->SetEDf(GPtr->GetTS() - enemy->GetJoin());

			}
			if (enemy->is_killed())
			{
				enemy->SetTd(GPtr->GetTS());
				GPtr->AddKilled(enemy);
			}
			else SUtemp.enqueue(enemy);
		}
		enemy = NULL;
	}
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
			cout << i;
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Earth units shot by AS" << GetId() << endl;
	}
}