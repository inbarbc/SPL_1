#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    offerCoalitions = new stack();
    // You can change the implementation of the constructor, but not the signature!
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

void Party::step(Simulation &s)
{
    if (getState() == CollectingOffers)
    {
        mTimer++;
        if (mTimer == 3)
        {
            // update from CollectingOffers to joined
            setState(Joined);
            // select a coalition according to policy
            mJoinPolicy.Join(offerCoalitions);
            // update the selected coalition
            // clone the agent
        }
    }

    // else - add an offer to stack offerCoalitions
}

void Party::addOffer(Coalition coalition)
{
    
}
