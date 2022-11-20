#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
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

///------------Rule of 5-------------///

//--------Destructor--------//
Agent::~Agent()
{
    delete mSelectionPolicy;
    mParties.clear();
}

//---------------- copy constructor-------------//
Agent::Agent(const Agent &other)
{
    for (int party: other.mParties)
    {
        mParties.push_back(party);
    }

    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy;
    mCoalitionId = other.mCoalitionId;
}

//-------------copy assignment operator------------//
Agent& Agent::operator=(const Agent& other)
{
    if(this == &other)
    {
        return *this;
    }
    else
    {
        delete mSelectionPolicy;
        mSelectionPolicy = nullptr;
        mSelectionPolicy = other.mSelectionPolicy;

        mParties.clear();

        for (int party: other.mParties)
        {
            mParties.push_back(party);
        }

        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        mCoalitionId = other.mCoalitionId;
        return *this;
    }
}

//-----------------move constructor-----------//
Agent::Agent(Agent &&other)
{
    for (int party: other.mParties)
    {
        mParties.push_back(party);
    }

    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy;
    mCoalitionId = other.mCoalitionId;
}

//------------- move assignment operator ---------//
Agent& Agent::operator=(Agent&& other)
{
    if(this == &other)
    {
        return *this;
    }

    delete mSelectionPolicy;
    mParties.clear();

    for (int party: other.mParties)
    {
        mParties.push_back(party);
    }

    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy;
    mCoalitionId = other.mCoalitionId;
    return *this;
}
