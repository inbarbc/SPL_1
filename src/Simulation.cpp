#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    vector<int> coalitions;
    int i = 0;

    for (Agent &agent : mAgents)
    {
        agent.setCoalitionId(i); i++;
        coalitions.push_back(mGraph.getMandates(agent.getPartyId()));
    }   
}

void Simulation::step()
{
    for (int i = 0; i <= mGraph.getNumVertices(); i++)
    {
        if(mGraph.getParty(i).getState() != Joined)
        {
            mGraph.getParty(i).step(*this);
        }
    }

    for (Agent &agent : mAgents)
    {
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    if (mAgents.empty()) {return true;}
    
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

void Simulation::removeAgent(Agent &agent)
{
    int i = 0;

    for (Agent &a : mAgents)
    {
        if (a.getId() == agent.getId())
        {
            mAgents.erase(mAgents.begin() + i);
            break;
        }
        else {i++;}
    }
}

vector<Agent> &Simulation::getAgents()
{
    return mAgents;
}
