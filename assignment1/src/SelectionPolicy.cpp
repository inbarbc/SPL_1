#include "../include/SelectionPolicy.h"

virtual void MandatesSelectionPolicy::select(const Graph &graph, Agent &agent, vector<Party> &parties)
{
    int m = 0;
    bool b = false;
    mSelectedParty = &parties[0];
   
    for (Party &party : parties)
    {
        if (!party.checkOffersFromCoalition(agent.getCoalitionId()))
        {
            if (party.getMandates() > m)
            {
                b = true;
                m = party.getMandates();
                mSelectedParty = &party;
            }
        }
        else {agent.removePartyFromList(party);}
    }
}

virtual void EdgeWeightSelectionPolicy::select(const Graph &graph, Agent &agent, vector<Party> &parties)
{
    int m = 0;
    mSelectedParty = &parties[0];

    for (Party &p : parties)
    {
        if (!p.checkOffersFromCoalition(agent.getCoalitionId()))
        {
            if (graph.getEdgeWeight(agent.getPartyId(),p.getId()) > m)
            {
                m = graph.getEdgeWeight(agent.getPartyId(),p.getId());
                mSelectedParty = &p;
            }
            else {agent.removePartyFromList(p);}
        }
    }
}