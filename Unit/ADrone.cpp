#include "ADrone.h"

ADrone::ADrone(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool ADrone::attack(Game* const & GPtr)
{
	bool flag = false;
	unit* enemy = NULL;
	//to be contninued after better understanding of the logic
	return flag;
}

void ADrone::printShots()
{
	cout << "AS " << GetId() << " shots [";
	int i;
	while (GetattackedIDs().dequeue(i))
		cout << i << " ";
	cout << "]\n";
}
