#include "Agent.h"

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

SelectionPolicy *Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}

void Agent::addPartyToList(const Party &party)
{
    mParties.push_back(party);
}

void Agent::removePartyFromList(const Party &party)
{
    int i = 0;
    bool b = false;

    for (const Party &p : mParties)
    {
        if (p.getId() == party.getId())
        {
            b = true;
            break;
        }
        else {i++;}              
    }
    if (b) {mParties.erase(mParties.begin() + i);}
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
    mSelectionPolicy->select(sim.getGraph(),*this,mParties);
    Party &party = *mSelectionPolicy->mSelectedParty;

    // update party
    if (party.getState() == Waiting) {party.setState(CollectingOffers);}
    party.addAgentToList(*this);

    // update agent
    removePartyFromList(party);
    if (mParties.empty()) {sim.removeAgentFromList(*this);}
}
