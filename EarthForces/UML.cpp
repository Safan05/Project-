#include "UML.h"

UML::UML()
{
	head = nullptr;
}

void UML::AddUnit()
{

}
bool UML::RemoveUnit(unit*& h) {
	int z;
	return dequeue(h, z);
}
UML::~UML()
{
	unit* temp; int z;
	while (dequeue(temp, z))
		delete temp;
}
