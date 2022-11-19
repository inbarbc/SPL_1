#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    vector<int> coalitions;
    int id = 0;

    for (Agent &agent : mAgents)
    {
        agent.setCoalitionId(id); id++;
        coalitions.push_back(mGraph.getMandates(agent.getPartyId()));
    }   
}

void Simulation::step()
{
    for (Party &party : mGraph.getParties())
    {
        party.step(*this);
    }

    for (Agent &agent : mAgents)
    {
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    for (int i = 0; i <= mGraph.getNumVertices(); i++)
    {
        if (mGraph.getParty(i).getState() != Joined) {return false;}
    }

    for (int coalition : mCoalitions)
    {
        if (coalition >= 61) {return true;}
    }

    return true;
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
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}

vector<int> &Simulation::getCoalitions()
{
    return mCoalitions;
}

void Simulation::addAgentToList(Agent &agent)
{
    mAgents.push_back(agent);
}

