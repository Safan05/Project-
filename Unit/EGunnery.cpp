#include "EGunnery.h"

EGunnery::EGunnery(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool EGunnery::attack(Game* const & GPtr)
{
    int EGshots = 0;
    LinkedQueue<unit*>templist; int gp;
    unit* enemy = nullptr;
    for (int i = 0; i < unit::GetAC() / 2; i++)
    {
        if (GPtr->GetAArmy().getAM().removeAlienMonster(enemy))
        {
            double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
            enemy->DecHealth(damage);
            if (!enemy->Wasattacked())
            {
                enemy->SetAttacked(true);     //mark as attacked
                enemy->SetTa(GPtr->GetTS());  //document time of fist attack
            }
            if (enemy->GetHealth() < 0)
                GPtr->EnqueueKilled(enemy);   //add to killed list
            else
                templist.enqueue(enemy);
        }
    }
    while (templist.dequeue(enemy))       //return alive monsters back
        GPtr->GetAArmy().getAM().AddAlienMonster(enemy);
    //attack drones
    return true;
}