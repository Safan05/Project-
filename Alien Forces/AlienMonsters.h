#pragma once
class unit;
class Game;
class AlienMonsters
{
	int count;     
	unit* monsters[1000];
public:
	AlienMonsters();
	bool pick(unit*&);                //picks a random monster from the array
	bool AddAlienMonster(unit*);      //add a monster to the array 
	bool removeAlienMonster(unit*&);  //remove a random monster from the array
	void PrintAM();
	int getCount();                   
	bool isEmpty();
	~AlienMonsters();
};