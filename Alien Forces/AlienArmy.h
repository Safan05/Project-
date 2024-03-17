#pragma once
#include"..\unit.h"
#include"AlienSoldiers.h"
#include"AlienMonsters.h"
#include"AlienDrones.h"
class game;
class AlienArmy
{
	Game* Gptr;               //pointer to the game class 
	AlienSoldiers AS;         //Alien Soldiers
	AlienDrones AD;    //Alien Drones
	AlienMonsters AM;                 //Alien Monsters 
	int id;
public:
	AlienArmy(Game* g = nullptr);
	bool AddAS(unit*);
	bool AddAM(unit*);
	bool AddAD(unit*);
	int getAlienCount();
	void PrintArmy();
};
