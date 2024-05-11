#pragma once
#include"../DS/LinkedQueue.h"
#include"../Unit/unit.h"

class unit;
class Game;
class UML : public LinkedQueue<unit*>
{
	int count;
public:
	UML();
	void AddUnit(unit*& u);
	bool RemoveUnit(unit*&);
	void RemoveOlderunits(Game* const& GPtr);
	void PrintUML();
	~UML();
};
