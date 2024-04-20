#pragma once
#include"../DS/priQueue.h"
#include"../Unit/unit.h"
class UML : public priQueue<unit*>
{
public:
	UML();
	void AddUnit();
	~UML();
};
