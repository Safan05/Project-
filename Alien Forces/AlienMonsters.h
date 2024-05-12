#pragma once
class unit;
class Game;
class AlienMonsters
{
	int count;
	unit* monsters[1000];
public:
	AlienMonsters();
	bool pick(unit*&);
	bool AddAlienMonster(unit*);
	bool removeAlienMonster(unit*&);
	void PrintAM();
	int getCount();
	bool isEmpty();
	~AlienMonsters();
};