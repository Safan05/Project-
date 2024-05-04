#pragma once
#ifndef UMLL
#define UMLL
#include"../DS/LinkedQueue.h"
class ETank;
class ESoldier;
class unit;
class UML : public LinkedQueue<unit*>
{
public:
	UML();
	void AddUnit(unit*& u);
	bool RemoveUnit(unit*&);
	~UML();
};

#endif // !

