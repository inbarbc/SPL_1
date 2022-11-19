#include "../include/SelectionPolicy.h"

void MandatesSelectionPolicy::select(Graph &graph, Agent &agent, vector<int> &parties)
{
    // select party
    int m = 0;
    mSelectedParty = &graph.getParty(parties[0]);

    for (int party : parties)
    {
        Party &p = graph.getParty(parties[party]);
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
}

void EdgeWeightSelectionPolicy::select(Graph &graph, Agent &agent, vector<int> &parties)
{
    // select party
    int m = 0;
    mSelectedParty = &graph.getParty(parties[0]);

    for (int party : parties)
    {
        Party &p = graph.getParty(parties[party]);
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
}