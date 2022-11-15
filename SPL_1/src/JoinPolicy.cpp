#include "JoinPolicy.h"
#include "Coalition.h"

JoinPolicy::JoinPolicy() {}

MandatesJoinPolicy::MandatesJoinPolicy():
{ 
}

void MandatesJoinPolicy::join(stack<Coalition> coalitions)
{   
    int maxMandates = 0;
    while(!coalitions.empty())
    {
        Coalition coalition = coalitions.pop();
        if(maxMandates < coalition.getMandates())
        {
            maxMandates = coalition.getMandates();
            Coalition coalition = coalitions.pop();
        }
    }
}

LastOfferJoinPolicy::LastOfferJoinPolicy():
{
}

void LastOfferJoinPolicy::join(stack<Coalition> coalitions)
{   
    Coalition coalition = coalitions.pop();
}