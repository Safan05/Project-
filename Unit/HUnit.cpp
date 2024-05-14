#include "HUnit.h"
#include "ESoldier.h"
#include "../Type.h"
HUnit::HUnit(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
	this->SetTa(0);
}

bool HUnit::attack(Game* const& Gptr)
{
	LinkedQueue<unit*> templist;
	unit* ToHeal = nullptr;
	for (int i = 0; i < this->GetAC(); i++)
	{
		if (Gptr->GetEArmy().GetUL().RemoveUnit(ToHeal))
		{
			double Healed = (this->GetPow() * this->GetHealth() / 100) / sqrt(ToHeal->GetHealth());
			ESoldier* Soldier = dynamic_cast<ESoldier*>(ToHeal);
			if(Soldier)
			if (Soldier->IsInfected()) {
				Soldier->setImuune(true);
				Soldier->SetInfected(false);
				Gptr->GetEArmy().GetES().incImmuneCount();
				Healed /= 2;
			}
			ToHeal->IncHealth(Healed);
			if (ToHeal->GetHPercent() < 20)
				templist.enqueue(ToHeal);
			else {
				if (Soldier)
					Gptr->GetEArmy().GetES().enqueue(ToHeal);
				else
					Gptr->GetEArmy().GetET().push(ToHeal);
				}
			}
		}
		while (templist.dequeue(ToHeal)) {
			Gptr->GetEArmy().GetUL().AddUnit(ToHeal);
		}
		this->DecHealth(this->GetHealth());
		return true;
	}

void HUnit::PrintAttacked()
{
}
