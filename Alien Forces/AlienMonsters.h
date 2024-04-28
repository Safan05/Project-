#pragma once
class unit;
class Game;
class AlienMonsters
{
	int count;
	unit* monsters[1000];
public:
	AlienMonsters();
	bool AddAlienMonster(unit*);
	bool removeAlienMonster(unit*&);
	void PrintAM();
	int getCount();
	bool AMattack(Game* const& GPtr);
	~AlienMonsters();
};