#include "ESoldier.h"

ESoldier::ESoldier(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
	Infected = false;
	immune = false;
}

bool ESoldier::attack(Game* const & GPtr)
{
	LinkedQueue<unit*> templist;
	LinkedQueue<unit*> Etemplist;
	unit* enemy = nullptr;
	
	if (!Infected)
	{
		setAWI(false);
		for (int i = 0; i < unit::GetAC(); i++)
		{
			if (GPtr->GetAArmy().getAS().dequeue(enemy))
			{
				//calculate the damage and decrement enemy's health
				double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
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
				else
					templist.enqueue(enemy);
			}
		}
		//return all units in temp list to their original list
		while (templist.dequeue(enemy))
			GPtr->GetAArmy().getAS().enqueue(enemy);
	}
	else
	{
		setAWI(true);
		for (int i = 0; i < unit::GetAC(); i++)
		{
			if (GPtr->GetEArmy().GetES().dequeue(enemy))
			{
				double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
				enemy->DecHealth(damage);
				GetattackedIDs().enqueue(enemy->GetId());
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
						ESoldier* es = dynamic_cast<ESoldier*>(enemy);
						es->setUmlJoinTime(GPtr->GetTS());
						GPtr->GetEArmy().GetUL().AddUnit(enemy);
					}
					//return all units in temp list to their original list
					else Etemplist.enqueue(enemy);
				}
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
		if (!getAWI()) {
			int id;
			cout << "ES " << GetId() << " shots [";
			while (GetattackedIDs().dequeue(id))
			{
				if (id > 10000)     //soldier is infected
					cout<< "\033[32m" << id - 10000 << "\033[0m";
				else
					cout << id;     //soldier is NOT infected
				if (!GetattackedIDs().isEmpty())
					cout << ", ";
			}
			cout << "] IDs of all Alien units shot by ES" << GetId() << endl;
		}
		else {
			int id;
			cout << "ES " << "\033[32m" << GetId() << "\033[0m" << " shots [";
			while (GetattackedIDs().dequeue(id))
			{
				if (id > 10000)
					cout << "\033[32m" << id - 10000 << "\033[0m";
				else
					cout << id;
				if (!GetattackedIDs().isEmpty())
					cout << ", ";
			}
			cout << "] IDs of all Earth units shot by ES" << "\033[32m" << GetId() << "\033[0m"<< endl;
		}
	}
	
}

void ESoldier::setAWI(bool t)
{
	AttackedWhileInfected = t;
}

bool ESoldier::getAWI()
{
	return AttackedWhileInfected;
}
