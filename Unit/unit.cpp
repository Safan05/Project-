#include "..\Unit\unit.h"
#include "..\Game\Game.h"
#include "ESoldier.h"
#include"HUnit.h"
#include<iostream>
using namespace std;
unit::unit(double H, int P, int AC, int T)
{
	Health = H;
	Power = P;
	AttackCapacity = AC;
	Type = T;
	Isattacked = false;
	id = -1;
	InitialHealth = H;
	Ta = 0;
	Td = 0;
}
int unit::GetId() {
	return id;
}
bool unit::is_killed()
{
	if (Health <= 0)
		return true;
	return false;
}


bool unit::operator>(const unit& a) const
{
	return Power > a.Power;
}

double unit::GetHPercent()
{
	return(Health / InitialHealth) * 100;
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

int unit::GetJoin()
{
	return JoinTime;
}

int unit::GetAC()
{
	return AttackCapacity;
}

int unit::GetPow()
{
	return Power;
}

double unit::GetHealth()
{
	return Health;
}

LinkedQueue<int>& unit::GetattackedIDs()
{
	return attacked_IDs;
}

void unit::DecHealth(double h)
{
	Health -= h;
}

void unit::IncHealth(double h)
{
Health += h;
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
	Ta = t;
}

int unit::GetTa()
{
	return Ta;
}

int unit::GetTd()
{
	return Td;
}

void unit::SetTd(int t)
{
	Td = t;
}

void unit::DeathReport(std::ofstream& wr)
{
	HUnit* h = dynamic_cast<HUnit*>(this);
	wr << Td << "\t\t\t" << id;
	wr<< "   \t\t\t\t"
		<< JoinTime << "\t\t\t\t";
	if (h)
		wr << "H";  //Heal units aren't attacked therefore have no Ta
	else
		wr << Ta - JoinTime;
	wr << "\t\t\t\t";
	if (h)         //Heal units aren't attacked therefore have no Ta
		wr << "0";
	else
		wr << Td - Ta;
	wr << "\t\t\t\t" << Td - JoinTime << endl;
}


void unit::PrintUnit()
{
	ESoldier* IsInfected = dynamic_cast<ESoldier*>(this);
	if (IsInfected) {
		if (IsInfected->IsInfected())
			cout << "\033[32m" << id << "\033[0m";
		else
			cout << id;
	}
	else
	cout << id;
}


