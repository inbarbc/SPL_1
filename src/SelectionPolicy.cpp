#include "../include/SelectionPolicy.h"

void MandatesSelectionPolicy::select(const Graph &graph, Agent &agent, vector<Party> &parties)
{
    int m = 0;
    bool b = false;
    mSelectedParty = &parties[0];
   
    for (Party &party : parties)
    {
        if (!party.offerChecking(agent.getCoalitionId()))
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

void EdgeWeightSelectionPolicy::select(const Graph &graph, Agent &agent, vector<Party> &parties)
{
    int m = 0;
    mSelectedParty = &parties[0];

    for (Party &p : parties)
    {
        if (!p.offerChecking(agent.getCoalitionId()))
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