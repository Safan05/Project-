#pragma once
#include"SaverUnits.h"
#include"..\Unit\unit.h"
class Game;
class AlliedArmy
{
	SaverUnits SU;    //list of saver units
	int id;
	unit* SUattacker; //saver unit attacking at current time step
public:
	AlliedArmy();
	bool AddUnit(unit*&);  //add a new saver unit to the list 
	SaverUnits& getSU();   //return the saver units list (to be used in attack)
	void PrintArmy();
	void SUattack(Game* const& Gptr);
	void printAttack();   //print all units attacked by a saver unit at current time step  
	void destroyArmy();   //delete all saver units (to be used if all infected soldiers are healed)  
};

