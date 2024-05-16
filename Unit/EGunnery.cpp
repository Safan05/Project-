#include "EGunnery.h"
#include"../Alien Forces/AlienDrones.h"
EGunnery::EGunnery(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool EGunnery::attack(Game* const & GPtr)
{
    LinkedQueue<unit*>templist; int gp;
    unit* enemy = nullptr;
    int ac = unit::GetAC();
    if (GPtr->GetAArmy().getAD().getCount() > 0) //to handle if Attack capacity is to be directed to one type of units
        ac = unit::GetAC() / 2;
    for (int i = 0; i < ac; i++)    //attack alien monsters
    {
        if (GPtr->GetAArmy().getAM().removeAlienMonster(enemy))
        {
            double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
            enemy->DecHealth(damage);
            GetattackedIDs().enqueue(enemy->GetId());
            if (!enemy->Wasattacked())
            {
                enemy->SetAttacked(true);     //mark as attacked
                enemy->SetTa(GPtr->GetTS());  //document time of fist attack
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
        GPtr->GetAArmy().getAM().AddAlienMonster(enemy);

    unit* denemy;
    unit* dummy = nullptr;
    AlienDrones ADtemp;
    for (int i = ac; i < unit::GetAC(); i++) //attack Alien Drones
    {
        
        if (GPtr->GetAArmy().getAD().dequeue(enemy,denemy))
        {
            if (enemy)
            {
                double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
                enemy->DecHealth(damage);
                GetattackedIDs().enqueue(enemy->GetId());
                if (!enemy->Wasattacked())
                {
                    enemy->SetAttacked(true);     //mark as attacked
                    enemy->SetTa(GPtr->GetTS());  //document time of fist attack
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
                }
                if (denemy->is_killed())
                {
                    denemy->SetTd(GPtr->GetTS());
                    GPtr->AddKilled(denemy);
                }
                else
                ADtemp.enqueue(dummy, denemy);
            }
        }
    }
    while (ADtemp.dequeue(enemy, denemy))
        GPtr->GetAArmy().getAD().enqueue(enemy, denemy);
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
