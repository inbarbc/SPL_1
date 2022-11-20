#include "../include/JoinPolicy.h"

void MandatesJoinPolicy::join(Party &party, vector<int> &coalitions,vector<Agent> &allAgents, vector<int> &myAgents)
{
    // select agent
    int m = 0;
    mSelectedAgent = &allAgents[myAgents[0]];

    for (int agent : myAgents)
    {
        if (coalitions[(*mSelectedAgent).getCoalitionId()] > m)
        {
            m = coalitions[(*mSelectedAgent).getCoalitionId()];
            mSelectedAgent = &allAgents[myAgents[agent]];
        }
    }

    // update coalition
    coalitions[(*mSelectedAgent).getCoalitionId()] += party.getMandates();

    // update party
    party.setState(Joined);

    // clone agent
    Agent clonedAgent = Agent(*mSelectedAgent);

}

void LastOfferJoinPolicy::join(Party &party, vector<int> &coalitions,vector<Agent> &allAgents, vector<int> &myAgents)
{
    mSelectedAgent = &allAgents[myAgents.back()];

    // update coalition
    coalitions[(*mSelectedAgent).getCoalitionId()] += party.getMandates();

    // update party
    party.setState(Joined);

    // clone agent
}