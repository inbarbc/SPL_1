#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
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

const vector<Agent> Party::getAgents() const
{
    return mAgents;
}

void Party::addAgentToList(Agent &agent)
{
    mAgents.push_back(agent);
}

const int Party::getId() const
{
    return mId;
}

bool Party::checkOffersFromCoalition(const int coalitionsId) const
{
    return mCoalitions[coalitionsId];
}

void Party::step(Simulation &s)
{   
    if (getState() == CollectingOffers)
    {
        mTimer++;
        if (mTimer == 3)
        {
            mJoinPolicy->join(s.getCoalitions(),mAgents);
            Agent &agent = *mJoinPolicy->mSelectedAgent;

            // update coalition
            s.getCoalitions()[agent.getCoalitionId()] += this->getMandates();

            // update party
            setState(Joined);

            // clone agent
            Agent *newAgent = new Agent(s.getAgents().size(),mId,agent.getSelectionPolicy());
            newAgent->setCoalitionId(agent.getCoalitionId());
            const Graph &graph = s.getGraph();

            for (const Party &party : graph.getParties())
            {
                if (graph.getEdgeWeight(mId,party.getId()) > 0)
                {
                    if ((party.getState() == Waiting) |
                     ((party.getState() == CollectingOffers) &
                      (!party.checkOffersFromCoalition(agent.getCoalitionId()))))
                    {
                        newAgent->addPartyToList(party);
                    }
                }
            }
            s.addAgentToList(agent);
        }
    }
}
