#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mCoalitions(0)
{
    int i = 0;

    for (Agent &agent : mAgents)
    {

        for (int j = 0; j < mGraph.getNumVertices(); j++)
        {
            if (mGraph.getEdgeWeight(agent.getPartyId(),j) > 0)
            {
                if (mGraph.getParty(j).getState() != Joined)
                {
                    agent.addParty(j); // partyId = partyIndex
                }
            }
        }

        agent.setCoalitionId(i); i++;
        mCoalitions.push_back(mGraph.getMandates(agent.getPartyId()));
    }   
}

void Simulation::step()
{
    for (int i = 0; i < mGraph.getNumVertices(); i++)
    {
        mGraph.getParty(i).step(*this);
    }

    for (Agent &agent : mAgents)
    {
        //if (!agent.getParties().empty()) {agent.step(*this);}
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{   
    if ((!collectingOffersParties()) & (!activeAgents())) {return true;}

    for (int i = 0; i <= mGraph.getNumVertices(); i++)
    {
        if (mGraph.getParty(i).getState() != Joined) {return false;}
    }

    for (const int coalition : mCoalitions)
    {
        if (coalition >= 61) {return true;}
    }

    return true;
}

const bool Simulation::collectingOffersParties() const
{
    for (int i = 0; i <= mGraph.getNumVertices(); i++)
    {
        if (mGraph.getParty(i).getState() == CollectingOffers) {return true;}
    }
    return false;
}

const bool Simulation::activeAgents() const
{
    for (const Agent agent : mAgents)
    {
        if (!agent.getParties().empty()) {return true;}
    }
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> coalitions;

    for (int i : mCoalitions)
    {
        vector<int> parties;

        for (const Agent &agent : mAgents)
        {
            if (agent.getCoalitionId() == i) {parties.push_back(agent.getPartyId());}
        }
        
        coalitions.push_back(parties);
    }

    return coalitions;
}

Graph &Simulation::getGraph()
{
    return mGraph;
}

vector<int> &Simulation::getCoalitions()
{
    return mCoalitions;
}

void Simulation::addAgent(Agent &agent)
{
    mAgents.push_back(agent);
}

vector<Agent> &Simulation::getAgents()
{
    return mAgents;
}
