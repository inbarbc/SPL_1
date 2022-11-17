#include "../include/JoinPolicy.h"

virtual void MandatesJoinPolicy::join(vector<int> coalitions, vector<Agent> &agents)
{
    int m = 0;
    mSelectedAgent = &agents[0];

    for (Agent &agent : agents)
    {
        if (coalitions[agent.getCoalitionId()] > m)
        {
            m = coalitions[agent.getCoalitionId()];
            mSelectedAgent = &agent;
        }
    }
}

virtual void LastOfferJoinPolicy::join(vector<int> coalitions, vector<Agent> &agents)
{
    mSelectedAgent = &agents[agents.size() - 1];
}