#pragma once
#include"../DS/LinkedQueue.h"
#include"../Unit/unit.h"
#include"../Unit/ESoldier.h"
#include"../Unit/ETank.h"
class UML : public LinkedQueue<unit*>
{
public:
	UML();
	void AddUnit(unit*& u);
	void AddUnit();
	bool RemoveUnit(unit*&);
	~UML();
};
