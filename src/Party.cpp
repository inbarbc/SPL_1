#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name),
 mMandates(mandates), mJoinPolicy(jp), mState(Waiting),
mTimer(0), mAgents(), mCoalitions(0), mLoadingCoalitionsVector(false)
{

}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

const vector<int> Party::getAgents() const
{
    return mAgents;
}

void Party::addAgent(int agentId)
{
    mAgents.push_back(agentId);
}

const int Party::getId() const
{
    return mId;
}

const bool Party::offerChecking(const int coalitionsId) const
{
    return mCoalitions[coalitionsId];
}

void Party::offerMarking(const int coalitionsId)
{
    mCoalitions[coalitionsId] = true;
}

void Party::step(Simulation &s)
{   
    if (!mLoadingCoalitionsVector)
    {
        for (int i = 0; i <= s.getIndex(); i++)
        {
            mCoalitions.push_back(false);
        }
        mLoadingCoalitionsVector = true;
    }

    if (getState() == CollectingOffers)
    {
        mTimer++;
        if (mTimer == 3) {mJoinPolicy->join(*this,s);}
    }
}

///------------Rule of 5-------------///

//--------Destructor--------//
Party::~Party()
{
    if (mJoinPolicy)
    {
        delete mJoinPolicy;
        mJoinPolicy = nullptr;
    }
    mCoalitions.clear();
}

//---------------- copy constructor-------------//
Party::Party(const Party &other) : mId(other.mId), mName(other.mName),
 mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState),
  mTimer(other.mTimer), mAgents(), mCoalitions(), mLoadingCoalitionsVector()
{
    for (int agent: other.mAgents)
    {
        mAgents.push_back(agent);
    }

    for (bool coatiltion: other.mCoalitions)
    {
        mCoalitions.push_back(coatiltion);
    }
}

//-------------copy assignment operator------------//
Party &Party::operator=(const Party &other)
{
    if(this == &other) {return *this;}
    else
    {
        delete mJoinPolicy;
        mJoinPolicy = nullptr;
        mJoinPolicy = other.mJoinPolicy->clone();
        
        mAgents.clear();
        mCoalitions.clear();

        for (int agent: other.mAgents)
        {
            mAgents.push_back(agent);
        }

        for (bool coatiltion: other.mCoalitions)
        {
            mCoalitions.push_back(coatiltion);
        }   

        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy->clone();
        mState = other.mState;
        mTimer = other.mTimer;
        return *this;
    }
}

//-----------------move constructor-----------//
Party::Party(Party &&other) : mId(other.mId), mName(other.mName),
 mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState),
  mTimer(other.mTimer), mAgents(), mCoalitions(), mLoadingCoalitionsVector()
{
    for (int agent: other.mAgents)
    {
        mAgents.push_back(agent);
    }

    for (bool coatiltion: other.mCoalitions)
    {
        mCoalitions.push_back(coatiltion);
    }
}

//------------- move assignment operator ---------//
Party& Party::operator=(Party&& other)
{
    if(this == &other)
    {
        return *this;
    }

    delete mJoinPolicy;
    mAgents.clear();
    mCoalitions.clear();

    for (int agent: other.mAgents)
    {
        mAgents.push_back(agent);
    }

    for (bool coatiltion: other.mCoalitions)
    {
        mCoalitions.push_back(coatiltion);
    }
    
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy->clone();
    mState = other.mState;
    return *this;
}

