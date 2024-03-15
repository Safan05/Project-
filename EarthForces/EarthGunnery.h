#ifndef EarthG
#define EarthG
#include"LinkedQueue.h"
#include"../unit.h";
class EarthGunnery
{
	LinkedQueue<unit> EGunnery;
	int Gcount;
public:
	EarthGunnery();
	bool EnqueueEGunnery(const unit& g);

};
#endif
