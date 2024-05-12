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
			double Healed = (this->GetPow() * (this->GetHealth() / 100)) / sqrt(ToHeal->GetHealth());
			ToHeal->IncHealth(Healed);
			ESoldier* IsInfected = dynamic_cast<ESoldier*>(ToHeal);
			if (IsInfected) {
				IsInfected->setImuune(true);
			}
			if (ToHeal->GetHPercent() < 20)
				templist.enqueue(ToHeal);
			else {
				if (IsInfected)
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
