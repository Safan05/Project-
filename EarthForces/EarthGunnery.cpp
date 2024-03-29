#include"EarthGunnery.h"
#include<iostream>
using namespace std;
EarthGunnery::EarthGunnery(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool EarthGunnery::Enqueue(unit* g)
{
    Gcount++;
    return priQueue<unit*>::enqueue(g, g->GetPow());
}

bool EarthGunnery::Dequeue(unit* g)
{
    Gcount--;
    int gp;
    return priQueue<unit*>::dequeue(g,gp);
}

bool EarthGunnery::attack(Game* ptr)
{
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
