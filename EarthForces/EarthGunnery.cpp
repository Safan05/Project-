#include"EarthGunnery.h"
#include"../DS/LinkedQueue.h"
#include"..\Game\Game.h"
#include<iostream>
using namespace std;
EarthGunnery::EarthGunnery()
{
    Gcount = 0;
}

bool EarthGunnery::enqueue(unit*& g)
{
    Gcount++;
    return priQueue<unit*>::enqueue(g, g->GetPow() + g->GetHealth());
}


bool EarthGunnery::dequeue(unit*& g)
{
    int gp;
    if (Gcount >= 0)
    if (priQueue<unit*>::dequeue(g, gp))
    {
        Gcount--;
        return true;
    }
    return false;
}


int EarthGunnery::GetGcount()
{
    return Gcount;
}

void EarthGunnery::PrintEG()
{
    priNode<unit*>* temp = head; int p;
    while (temp)
    {
        temp->getItem(p)->PrintUnit();
        if (temp->getNext())      //Printing style fix
            cout << ", ";
        temp = temp->getNext();
    }
}

EarthGunnery::~EarthGunnery()
{
    unit* temp = nullptr;
    while (this->dequeue(temp))
    {
        delete temp;
    }
}
