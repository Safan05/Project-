#include "unit.h"
#include<iostream>
using namespace std;
unit::unit( double H, int P, int AC, int T)
{
	//id = I;
	//JoinTime = JT;
	Health = H;
	Power = P;
	AttackCapacity = AC;
	Type = T;
	Isattacked = false;
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

int unit::GetAC()
{
	return AttackCapacity;
}

int unit::GetPow()
{
	return Power;
}

int unit::GetHealth()
{
	return Health;
}

void unit::DecHealth(double h)
{
	Health -= h;
}

void unit::SetAttacked(bool a)
{
	Isattacked = a;
}

bool unit::Wasattacked()
{
	return Isattacked;
}

void unit::SetTa(int t)
{
	ImpTime[1] = t;
}

void unit::SetTd(int t)
{
	ImpTime[2] = t;
}

void unit::DeathReport(std::ofstream& wr)
{
	wr  << ImpTime[2] << "\t" << id << "\t"
		<< JoinTime << "\t" << ImpTime[1] - ImpTime[0] << "\t"
		<< ImpTime[2] - ImpTime[1] << "\t" << ImpTime[2] - ImpTime[0] << endl;
}


void unit::PrintUnit()
{
	cout << id;
}


