#include "ESoldier.h"

ESoldier::ESoldier(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
	Infected = false;
}

bool ESoldier::attack(Game* const & GPtr)
{
	LinkedQueue<unit*> templist;
	LinkedQueue<unit*> Etemplist;
	unit* enemy = nullptr;
	
	if (!Infected)
	{
		for (int i = 0; i < unit::GetAC(); i++)
		{
			if (GPtr->GetAArmy().getAS().dequeue(enemy))
			{
				double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
				enemy->DecHealth(damage);
				GetattackedIDs().enqueue(enemy->GetId());
				if (!enemy->Wasattacked())
				{
					GPtr->GetAArmy().IncAttackCount();
					enemy->SetAttacked(true);
					enemy->SetTa(GPtr->GetTS());
					GPtr->SetADf(GPtr->GetTS() - enemy->GetJoin());
				}
				if (enemy->is_killed())
				{
					enemy->SetTd(GPtr->GetTS());
					GPtr->AddKilled(enemy);
				}
				else
					templist.enqueue(enemy);
			}
		}
		while (Etemplist.dequeue(enemy))
			GPtr->GetAArmy().getAS().enqueue(enemy);
	}
	else
	{
		for (int i = 0; i < unit::GetAC(); i++)
		{
			if (GPtr->GetEArmy().GetES().dequeue(enemy))
			{
				double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
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
					Etemplist.enqueue(enemy);
			}
		}
		while (Etemplist.dequeue(enemy))
			GPtr->GetEArmy().GetES().enqueue(enemy);
	}
	
	return true;
}

void ESoldier::SetInfected(bool v)
{
	Infected = v;
}

void ESoldier::setImuune(bool im)
{
	immune = im;
}

bool ESoldier::isImmune()
{
	return immune;
}


bool ESoldier::IsInfected()
{
	return Infected;
}

void ESoldier::SpreadInfection(Game* const& GPtr)
{
	if (this->IsInfected())
	{
		//to be implemented later
		bool notinfected = true;
		while (notinfected)
		{
			int c = rand() % GPtr->GetEArmy().GetES().GetScount();
		}
	}
}

void ESoldier::setUmlJoinTime(int t)
{
	UmlJoinTime = t;
}

int ESoldier::getUmlJoinTime()
{
	return UmlJoinTime;
}

void ESoldier::PrintAttacked()
{
	if (!GetattackedIDs().isEmpty())
	{
		int id;
		cout << "ES " << GetId() << " shots [";
		while (GetattackedIDs().dequeue(id))
		{
			cout << id;
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Alien units shot by ES" << GetId() << endl;
	}

}
