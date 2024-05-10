#pragma once
#ifndef UMLL
#define UMLL
#include"../Unit/unit.h"
#include"../DS/LinkedQueue.h"
class ETank;
class ESoldier;
class Game;
class UML : public LinkedQueue<unit*>
{
public:
	UML();
	void AddUnit(unit*& u);
	bool RemoveUnit(unit*&);
	~UML();
};

#endif // !

