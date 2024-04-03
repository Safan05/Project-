#ifndef EArmy
#define EArmy
#include"Soldier.h";
#include"ETank.h"
#include"EGunnery.h"
#include"EarthSoldiers.h"
#include"EarthTanks.h"
#include"EarthGunnery.h"
class Game;
class EarthArmy
{
	Game* Gptr;
	EarthSoldiers ES;
	EarthGunnery EG;
	EarthTanks ET;
	int id;
public:
	EarthArmy(Game* g = nullptr);
	bool AddUnit(unit*, Type t);
	bool AddES(unit* s);
	bool AddET(unit* t);
	bool AddEG(unit* g);
	EarthSoldiers& GetES();
	EarthGunnery& GetEG();
	EarthTanks& GetET();
	void PrintArmy();
};
#endif
