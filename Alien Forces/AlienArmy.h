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
	AlienSoldiers AS;         //Alien Soldiers
	AlienDrones AD;			  //Alien Drones
	AlienMonsters AM;         //Alien Monsters 
	int id;
	int AttackCount;
public:
	AlienArmy();
	bool AddUnit(unit*&);
	AlienSoldiers& getAS();
	AlienMonsters& getAM();
	AlienDrones& getAD();
	int getAlienCount();
	void IncAttackCount();
	int GetAttackCount();
	void Alienattack(Game* const& GPtr);
	void PrintArmy();
	void PrintAttack();
};
#endif