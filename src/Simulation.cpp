#include "Simulation.h"
#include "Coalition.h"
#include <vector>

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!

    for (Agent agent : mAgents)
    {
        mCoalitions.push_back(Coalition(agent.getId(),mGraph.getMandates(agent.getPartyId())));
    }

}

void Simulation::step()
{
    for (int i = 0; i <= mGraph.getNumVertices(); i++)
    {
        Party party = getParty(i);
        party.step(*this);
    }

    for (Agent agent : mAgents)
    {
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    for (int i = 0; i <= mGraph.getNumVertices(); i++)
    {
        if (getParty(i).getState() != Joined) {return false;}
    }

    for (Coalition coalition : mCoalitions)
    {
        if (coalition.getMandates() >= 61) {return true;}
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
