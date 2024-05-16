#pragma once
#include"..\DS\DoubleQueue.h"
class unit;
class Game;
class AlienDrones :public DoubleQueue<unit*>
{
	int count;
public:
	AlienDrones();
	bool enqueue(unit*& front, unit*& back);   //enqueue drones at the front and at the back of the list (approved)
	bool dequeue(unit*&, unit*&);              //dequeue drones from the front and the back of the list (approved)
	bool peek(unit*&, unit*&);                 //return true only if two drones or more exist   
	void PrintAD();
	int getCount();
	~AlienDrones();
};