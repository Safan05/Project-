#ifndef EArmy
#define EArmy
#include"EarthSoldiers.h"
#include"EarthTanks.h"
#include"EarthGunnery.h"
#include"UML.h"
#include"HealUnits.h"
#include"..\Unit\unit.h"
#include"..\Type.h"
class Game;
class EarthArmy
{
	// The Lists that the Earth army contains
	EarthSoldiers ES;
	EarthGunnery EG;
	EarthTanks ET;
	UML UL;
	HealUnits HU;
	// id and attacked units counter
	int id;
	int AttackCount;
	// pointers to store the attacker units to print it after battle 
	unit* ESattacker;	
	unit* ETattacker;
	unit* EGattacker;
public:
	EarthArmy();
	bool AddUnit(unit*&);
	EarthSoldiers& GetES();
	EarthGunnery& GetEG();
	EarthTanks& GetET();
	UML& GetUL();
	void IncAttackCount();
	int GetAttackCount();
	void PrintAttack();
	void PrintArmy();
	void EarthAttack(Game* const& Gptr);
};
#endif
