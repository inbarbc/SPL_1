#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    mCoalitionId = NULL;
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

const vector<int> &Agent::getParties() const
{
    return mParties;
}

void Agent::addParty(int partyId)
{
    mParties.push_back(partyId);
}

void Agent::removeParty(int partyId)
{
    int i = 0;

    for (int pId : mParties)
    {
        if (pId == partyId)
        {
            mParties.erase(mParties.begin() + i);
            break;
        }
        else {i++;}              
    }
}

const int Agent::getCoalitionId() const
{
    return mCoalitionId;
}

void Agent::setCoalitionId(int coalitionId)
{
    mCoalitionId = coalitionId;
}

void Agent::step(Simulation &sim)
{   
    (*mSelectionPolicy).select(sim.getGraph(),*this,mParties);
    if (mParties.empty()) {sim.removeAgent(*this);}
}
