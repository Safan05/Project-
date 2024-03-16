#ifndef EarthS
#define EarthS
#include"../unit.h";
class EarthSoldiers:public unit
{
	
public:
	EarthSoldiers(int H, int P, int AC, int T);
	bool attack();
	bool AddtoKilled(const unit* u);

};
#endif
