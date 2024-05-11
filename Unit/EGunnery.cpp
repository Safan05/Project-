#include "EGunnery.h"
#include"../Alien Forces/AlienDrones.h"
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
        if (GPtr->GetAArmy()->getAM().removeAlienMonster(enemy))
        {
            double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
            enemy->DecHealth(damage);
            GetattackedIDs().enqueue(enemy->GetId());
            if (!enemy->Wasattacked())
            {
                GPtr->GetAArmy()->IncAttackCount();
                enemy->SetAttacked(true);     //mark as attacked
                enemy->SetTa(GPtr->GetTS());  //document time of fist attack
                GPtr->SetADf(GPtr->GetTS() - enemy->GetJoin());
            }
            if (enemy->GetHealth() <= 0)
            {
                enemy->SetTd(GPtr->GetTS());
                GPtr->AddKilled(enemy);
            }                                      //add to killed list
            else
                templist.enqueue(enemy);
        }
    }
    while (templist.dequeue(enemy))       //return alive monsters back
        GPtr->GetAArmy()->getAM().AddAlienMonster(enemy);
    unit* denemy;
    unit* dummy = nullptr;
    AlienDrones ADtemp;
    for (int i = unit::GetAC() / 2; i < unit::GetAC(); i++)
    {
        
        if (GPtr->GetAArmy()->getAD().dequeue(enemy,denemy))
        {
            if (enemy)
            {
                double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
                enemy->DecHealth(damage);
                GetattackedIDs().enqueue(enemy->GetId());
                if (!enemy->Wasattacked())
                {
                    GPtr->GetAArmy()->IncAttackCount();
                    enemy->SetAttacked(true);     //mark as attacked
                    enemy->SetTa(GPtr->GetTS());  //document time of fist attack
                    GPtr->SetADf(GPtr->GetTS() - enemy->GetJoin());
                }
                if (enemy->is_killed())
                {
                    enemy->SetTd(GPtr->GetTS());
                    GPtr->AddKilled(enemy);
                }
                else
                    ADtemp.enqueue(enemy, dummy);
            }
            if (denemy)
            {
                double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(denemy->GetHealth());
                denemy->DecHealth(damage);
                GetattackedIDs().enqueue(denemy->GetId());
                if (!denemy->Wasattacked())
                {
                    denemy->SetAttacked(true);     //mark as attacked
                    denemy->SetTa(GPtr->GetTS());  //document time of fist attack
                    GPtr->SetADf(GPtr->GetTS() - enemy->GetJoin());
                }
                if (denemy->is_killed())
                {
                    denemy->SetTd(GPtr->GetTS());
                    GPtr->AddKilled(enemy);
                }
                else
                    ADtemp.enqueue(dummy, denemy);
            }
        }
    }
    return true;
}

void EGunnery::PrintAttacked()
{
    if (!GetattackedIDs().isEmpty())
    {
        int id;
        cout << "EG " << GetId() << " shots [";
        while (GetattackedIDs().dequeue(id))
        {
            cout << id;
            if (!GetattackedIDs().isEmpty())
                cout << ", ";
        }
        cout << "] IDs of all Alien units shot by EG" << GetId() << endl;
    }
}
