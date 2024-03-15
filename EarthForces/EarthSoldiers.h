#ifndef EarthS
#define EarthS
#include"LinkedQueue.h"
#include"../unit.h";
class EarthSoldiers:public unit
{
	LinkedQueue<unit> ESoldiers;
	int Scount;
public:
	EarthSoldiers(int H, int P, int AC, int T);
	bool EnqueueESoldier(const unit& s);
	bool attack();
	bool AddtoKilled(const unit& u);

};
#endif
