#include "unit.h"
#include<iostream>
using namespace std;
unit::unit( int H, int P, int AC, int T)
{
	//id = I;
	//JoinTime = JT;
	Health = H;
	Power = P;
	AttackCapacity = AC;
	Type = T;
}

bool unit::is_killed()
{
	if(Health<=0)
		return true;
	return false;
}


bool unit::operator>(const unit& a) const
{
	return Power > a.Power;
}

int unit::GetType() {
	return Type;
}
void unit::SetId(int I) {
	id = I;
}
void unit::SetJoin(int J) {
	JoinTime = J;
}

void unit::PrintUnit()
{
	cout << id;
}


