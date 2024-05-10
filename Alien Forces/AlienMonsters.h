#pragma once
class unit;
class Game;
class AlienMonsters
{
	int count;
	unit* attacker;
	unit* monsters[1000];
public:
	AlienMonsters();
	bool pick(unit*&);         //picks a random monster from the array
	void setattacker(unit*);   //to keep the monster which made the attack (to print the attacked list )
	unit* getAttacker();       //to get the monster which made the attack 
	bool AddAlienMonster(unit*);       //add a monster to the array
	bool removeAlienMonster(unit*&);   //remove a random monster from the array
	void PrintAM();    
	int getCount();
	~AlienMonsters();
};