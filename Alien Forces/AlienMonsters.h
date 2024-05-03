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
	bool pick(unit*);
	bool AddAlienMonster(unit*);
	bool removeAlienMonster(unit*&);
	unit* getAttacker();
	void setattacker(unit*);
	void PrintAM();
	int getCount();
	~AlienMonsters();
};