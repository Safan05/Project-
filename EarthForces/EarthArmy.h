#ifndef EArmy
#define EArmy
#include"EarthSoldiers.h"
#include"EarthTanks.h"
#include"EarthGunnery.h"
#include"..\Unit\unit.h"
#include"..\Type.h"
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
	bool AddUnit(unit*&);
	EarthSoldiers& GetES();
	EarthGunnery& GetEG();
	EarthTanks& GetET();
	void PrintArmy();
};
#endif
