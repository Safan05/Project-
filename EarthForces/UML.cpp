#include "UML.h"
#include "..\Game\Game.h"
#include"../Unit/ESoldier.h"
#include"../Unit/ETank.h"
UML::UML()
{
	
}

void UML::AddUnit(unit*& u)
{
	Node<unit*>* nptr = new Node<unit*>(u);
	if (isEmpty()) {
		frontPtr = nptr;
		backPtr = nptr;
	}
	else
	{
		ETank* tank = dynamic_cast<ETank*>(u);
		ESoldier* soldier = dynamic_cast<ESoldier*>(u);
		if (tank)
		{
			backPtr->setNext(nptr);
			backPtr = backPtr->getNext();
		}
		else if (soldier)
		{
			ETank* t = dynamic_cast<ETank*>(frontPtr->getItem());
			if (frontPtr->getItem()->GetHealth() > u->GetHealth() || t)
			{
				nptr->setNext(frontPtr); frontPtr = nptr;
			}
			else
			{
				Node<unit*>* ptr = frontPtr;
				while (ptr->getNext() && (ptr->getNext()->getItem()->GetType() == 0) && ptr->getNext()->getItem()->GetHealth() < u->GetHealth())
					ptr = ptr->getNext();
				nptr->setNext(ptr->getNext());
				ptr->setNext(nptr);
			}
		}
	
	}
}

bool UML::RemoveUnit(unit*& h) {
	int z;
	return dequeue(h);
}

UML::~UML()
{
	unit* temp; int z;
	while (dequeue(temp))
		delete temp;
}
