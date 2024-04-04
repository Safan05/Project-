#ifndef AArmy
#define AArmy
#include"AlienSoldiers.h"
#include"AlienMonsters.h"
#include"AlienDrones.h"
#include"../Type.h"
class Game;
class unit;
class AlienArmy
{
	Game* Gptr;               //pointer to the game class 
	AlienSoldiers AS;         //Alien Soldiers
	AlienDrones AD;			  //Alien Drones
	AlienMonsters AM;         //Alien Monsters 
	int id;
public:
	AlienArmy(Game* g = nullptr);
	bool AddAS(unit*);
	bool AddAM(unit*);
	bool AddAD(unit*);
	AlienSoldiers& getAS();
	AlienMonsters& getAM();
	AlienDrones& getAD();
	int getAlienCount();
	void PrintArmy();
};
#endif