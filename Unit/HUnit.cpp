#include "HUnit.h"
#include "../Type.h"
HUnit::HUnit(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
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
			if (ToHeal->GetHPercent() < 20)
				templist.enqueue(ToHeal);
			else {
				if (ToHeal->GetType() == earthsoldier)
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
