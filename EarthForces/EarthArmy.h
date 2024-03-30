#ifndef EArmy
#define EArmy
#include"../unit.h";
#include"EarthSoldiers.h"
#include"EarthTank.h"
#include"EarthGunnery.h"
class Game;
class EarthArmy
{
	Game* Gptr;
	EarthSoldiers ESoldiers;
	EarthGunnery EGunnery;
	EarthTank ETanks;
	int id;
public:
	EarthArmy(Game* g = nullptr);
	bool EnqueueESoldier(unit* s);
	bool EnqueueETank(unit* t);
	bool EnqueueEGunnery(unit* g);
	EarthSoldiers& GetES();
	EarthGunnery& GetEG();
	EarthTank& GetET();
	void PrintArmy();
};
#endif
