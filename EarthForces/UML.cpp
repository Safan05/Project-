#include "UML.h"

UML::UML()
{
	head = nullptr;
}

void UML::AddUnit()
{

}

UML::~UML()
{
	unit* temp; int z;
	while (dequeue(temp, z))
		delete temp;
}
