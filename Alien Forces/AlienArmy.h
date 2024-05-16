#ifndef AArmy
#define AArmy
#include"AlienSoldiers.h"
#include"AlienMonsters.h"
#include"AlienDrones.h"
#include"..\Unit\unit.h"
#include"..\Type.h"
class Game;
class AlienArmy
{
	// The Lists that the alien army contains
	AlienSoldiers AS;         
	AlienDrones AD;			  
	AlienMonsters AM;         
	//allien units attacking at current time step
	unit* ASattacker, * ADattacker_1, * ADattacker_2, * AMattacker;  
	// id and NO. attacked alien units
	int id;
	int AttackCount;          
public:
	AlienArmy();
	bool AddUnit(unit*&);      //add new unit to its suitable list
	//getters for the alien lists (to be used int attack)
	AlienSoldiers& getAS();
	AlienMonsters& getAM();
	AlienDrones& getAD();
	//getters for the alien units total count and attacked count
	int getAlienCount();
	int GetAttackCount();
	void IncAttackCount();      //increment attacked count
	void Alienattack(Game* const& GPtr);
	void PrintArmy();           //print alive allien forces
	void PrintAttack();         //print units attacked by allien forces at current time step
};
#endif