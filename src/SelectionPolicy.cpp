#include "../include/SelectionPolicy.h"

SelectionPolicy::~SelectionPolicy(){}
MandatesSelectionPolicy::~MandatesSelectionPolicy(){};
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){};

MandatesSelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy(*this);
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy(*this);
}

void MandatesSelectionPolicy::select(Graph &graph, Agent &agent, vector<int> &parties)
{
    // select party
    int m = 0;
    Party *mSelectedParty;

    for (int party : parties)
    {
        Party &p = graph.getParty(party);
        if (!p.offerChecking(agent.getCoalitionId()))
        {
            if (p.getMandates() > m)
            {
                m = p.getMandates();
                mSelectedParty = &p;
            }
        }
        else {agent.removeParty(party);}
    }
    
    // update party
    if ((*mSelectedParty).getState() == Waiting) {(*mSelectedParty).setState(CollectingOffers);}
    (*mSelectedParty).addAgent(agent.getId());

    // update agent
    agent.removeParty((*mSelectedParty).getId());

    // update coalition
    mSelectedParty->offerMarking(agent.getCoalitionId());
}

void EdgeWeightSelectionPolicy::select(Graph &graph, Agent &agent, vector<int> &parties)
{
    // select party
    int m = 0;
    Party *mSelectedParty;

    for (int party : parties)
    {
        Party &p = graph.getParty(party);
        if (!p.offerChecking(agent.getCoalitionId()))
        {
            if (graph.getEdgeWeight(agent.getPartyId(),party) > m)
            {
                m = graph.getEdgeWeight(agent.getPartyId(),party);
                mSelectedParty = &p;
            }
        }
        else {agent.removeParty(party);}
    }
    
    // update party
    if ((*mSelectedParty).getState() == Waiting) {(*mSelectedParty).setState(CollectingOffers);}
    (*mSelectedParty).addAgent(agent.getId());

    // update agent
    agent.removeParty((*mSelectedParty).getId());

    // update coalition
    mSelectedParty->offerMarking(agent.getCoalitionId());
}