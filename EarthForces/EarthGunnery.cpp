#include"EarthGunnery.h"
#include"../DS/LinkedQueue.h"
#include"..\Game\Game.h"
#include<iostream>
using namespace std;
EarthGunnery::EarthGunnery(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool EarthGunnery::enqueue(unit* g)
{
    Gcount++;
    return priQueue<unit*>::enqueue(g, g->GetPow());
}


bool EarthGunnery::dequeue(unit* g)
{
    Gcount--;
    int gp;
    return priQueue<unit*>::dequeue(g,gp);
}

bool EarthGunnery::attack(Game* Gptr)
{
    LinkedQueue<unit*>templist;
    unit* enemy = nullptr;
    for (int i = 0; i < unit::GetAC(); i++)
    {
        if (Gptr->GetAArmy().getAM().removeAlienMonster(enemy))
        {
            double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
            enemy->DecHealth(damage);
            if (!enemy->Wasattacked())
            {
                enemy->SetAttacked(true);     //mark as attacked
                enemy->SetTa(Gptr->GetTS());  //document time of fist attack
            }
            if (enemy->GetHealth() < 0)
            {
                Gptr->EnqueueKilled(enemy);   //add to killed list
            }
            else {
                templist.enqueue(enemy);
            }
        }
        else
            return false;    //no unit to attack
    }
    while (templist.dequeue(enemy))       //return alive monsters back
        Gptr->GetAArmy().AddAM(enemy);
    return true;
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
