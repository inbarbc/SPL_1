#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId),
 mSelectionPolicy(selectionPolicy), mParties(0), mCoalitionId(-1)
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

Agent::Agent(const Agent &other,int agentId,int partyId) : mAgentId(other.mAgentId), mPartyId(other.mPartyId),
 mSelectionPolicy(other.mSelectionPolicy), mParties(), mCoalitionId(other.mCoalitionId)
{
    mAgentId = agentId;
    mPartyId = partyId;
    mSelectionPolicy = other.mSelectionPolicy->clone();
    mParties.clear();
    mCoalitionId = other.mCoalitionId;
}

void Agent::step(Simulation &sim)
{   
    (*mSelectionPolicy).select(sim.getGraph(),*this,mParties);
}

///------------Rule of 5-------------///

//--------Destructor--------//
Agent::~Agent()
{
    //delete mSelectionPolicy;
    //mParties.clear();
}

//---------------- copy constructor-------------//
Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId),
 mSelectionPolicy(other.mSelectionPolicy->clone()), mParties(), mCoalitionId(other.mCoalitionId)
{
    for (int party: other.mParties)
    {
        mParties.push_back(party);
    }
}

//-------------copy assignment operator------------//
Agent &Agent::operator=(const Agent &other)
{
    if(this == &other) {return *this;}
    else
    {
        delete mSelectionPolicy;
        mSelectionPolicy = nullptr;
        mSelectionPolicy = other.mSelectionPolicy->clone();
        
        mParties.clear();
        for (int party: other.mParties)
        {
            mParties.push_back(party);
        }  

        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mCoalitionId = other.mCoalitionId;
        return *this;
    }
}

//-----------------move constructor-----------//
Agent::Agent(Agent &&other): mAgentId(other.mAgentId), mPartyId(other.mPartyId),
 mSelectionPolicy(other.mSelectionPolicy->clone()), mParties(), mCoalitionId(other.mCoalitionId)
{
    for (int party: other.mParties)
    {
        mParties.push_back(party);
    }
}

//------------- move assignment operator ---------//
Agent &Agent::operator=(Agent &&other)
{
    if(this == &other) {return *this;}
    else
    {
        delete mSelectionPolicy;
        other.mSelectionPolicy = nullptr;

        mParties.clear();

        for (int party: other.mParties)
        {
            mParties.push_back(party);
        }    
    
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->clone();
        mCoalitionId = other.mCoalitionId;
        return *this;
    }
}
