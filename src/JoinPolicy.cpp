#include "../include/JoinPolicy.h"

JoinPolicy::~JoinPolicy(){}

MandatesJoinPolicy::~MandatesJoinPolicy(){}

void MandatesJoinPolicy::join(Party &party, vector<int> &coalitions,vector<Agent> &allAgents, vector<int> &myAgents)
{
    // select agent
    int m = 0;
    Agent mSelectedAgent = allAgents[myAgents[0]];

    for (int agent : myAgents)
    {
        if (coalitions[(mSelectedAgent).getCoalitionId()] > m)
        {
            m = coalitions[(mSelectedAgent).getCoalitionId()];
            mSelectedAgent = allAgents[myAgents[agent]];
        }
    }

    // update coalition
    coalitions[(mSelectedAgent).getCoalitionId()] += party.getMandates();

    // update party
    party.setState(Joined);

    // clone agent
}

LastOfferJoinPolicy::~LastOfferJoinPolicy(){}

void LastOfferJoinPolicy::join(Party &party, vector<int> &coalitions,vector<Agent> &allAgents, vector<int> &myAgents)
{
    Agent mSelectedAgent = allAgents[myAgents.back()];

    // update coalition
    coalitions[(mSelectedAgent).getCoalitionId()] += party.getMandates();

    // update party
    party.setState(Joined);

    // clone agent
    allAgents.push_back(mSelectedAgent);
}