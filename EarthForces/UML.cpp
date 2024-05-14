#include "UML.h"
#include "..\Game\Game.h"
#include"../Unit/ESoldier.h"
#include"../Unit/ETank.h"
UML::UML()
{
	count = 0;
}

void UML::AddUnit(unit*& u)
{
	if (u) {
		count++;
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
					nptr->setNext(frontPtr);
					frontPtr = nptr;
				}
				else
				{
					Node<unit*>* ptr = frontPtr;
					while (ptr->getNext() && (ptr->getNext()->getItem()->GetType() == 0) && (ptr->getNext()->getItem()->GetHealth() < u->GetHealth()))
						ptr = ptr->getNext();
					nptr->setNext(ptr->getNext());
					ptr->setNext(nptr);
				}
			}
			Node<unit*>* ptr = frontPtr;
			while (ptr->getNext())
				ptr = ptr->getNext();
			backPtr = ptr;
		}

	}
}

bool UML::RemoveUnit(unit*& h) {
	int z;
	if (dequeue(h))
	{
		count--;
		return true;
	}
	return false;
}

void UML::RemoveOlderunits(Game* const& GPtr)
{
	LinkedQueue<unit*> temp;
	unit* u = NULL;
	while (RemoveUnit(u))
	{
		ESoldier* es = dynamic_cast<ESoldier*>(u);
		if (es)
		{
			if (GPtr->GetTS() - es->getUmlJoinTime() >= 10) {
				GPtr->AddKilled(u);
			}
			else 
				temp.enqueue(u);
			
		}
		else
		{
			ETank* et = dynamic_cast<ETank*>(u);
			if (GPtr->GetTS() - et->getUmlJoinTime() >= 10) {
				GPtr->AddKilled(u);
			}
			else 
				temp.enqueue(u);
		}
	}
	while (temp.dequeue(u))
		this->AddUnit(u);
}

void UML::PrintUML()
{
	Node<unit*>* temp = frontPtr;
	cout << count << " units [";
	while (temp)
	{
		temp->getItem()->PrintUnit();
		if (temp->getNext())     //Printing style fix
			cout << ", ";
		temp = temp->getNext();
	}
	cout << "]";
}
UML::~UML()
{
	unit* temp; int z;
	while (dequeue(temp))
		delete temp;
}
