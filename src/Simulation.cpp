#include "Simulation.h"
#include <vector>

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
    vector<Coalition> mCoalitions;
    for (Agent agent : mAgents)
    {
        int PartyMandates = mGraph.getMandates(agent.getPartyId());
        mCoalitions.push_back(Coalition(agent.getId(), PartyMandates));
    }
}

void Simulation::step()
{
    // TODO: implement this method
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    for (Coalition coalition : getCoalitions())
    {

    }

    for (Party vertice : mGraph.getVertices())
    {
        if (vertice.getState() != Joined) {return false;}
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


vector<Coalition> &Simulation::getCoalitions() const
{
    return mCoalitions;
}